#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct Node {
    char val;
    Node* left;
    Node* right;
    Node(char c, Node* left = nullptr, Node* right = nullptr): val{c}, left{left}, right{right} {}
};

void printBT(const std::string& prefix, const Node* node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix << (isLeft ? "├──" : "└──" ) << node->val << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const Node* node) {
    printBT("", node, false);    
}

bool comparePair(const pair<int, Node*>& p1, const pair<int, Node*>& p2) {
    return p1.first > p2.first;
}

template<typename T>
void popHeap(vector<T>& v) {
    pop_heap(v.begin(), v.end(), comparePair);
    v.pop_back();
}

template<typename T>
void pushHeap(vector<T>& v, T& t) {
    v.push_back(t);
    push_heap(v.begin(), v.end(), comparePair);
}

Node* huffmanEncoding(vector<char>& chars, vector<int>& freqs) {
    vector<pair<int, Node*>> v;
    for (int i = 0; i < chars.size(); i++) {
        v.push_back(make_pair(freqs[i], new Node(chars[i])));
    }
    make_heap(v.begin(), v.end(), comparePair);

    while (v.size() > 1) {
        pair<int, Node*> p1 = v.front();
        popHeap(v);
        pair<int, Node*> p2 = v.front();
        popHeap(v);

        pair<int, Node*> newPair = make_pair(p1.first + p2.first, new Node('*', p1.second, p2.second));
        pushHeap(v, newPair);
    }
    return v.front().second;
}

int main() {
    vector<char> chars{'a', 'b', 'c', 'd', 'e'};
    vector<int> freqs{1, 2, 3, 4, 5};
    Node* HuffmanTree = huffmanEncoding(chars, freqs);
    printBT(HuffmanTree);
}