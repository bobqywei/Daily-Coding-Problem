#include<deque>
#include<vector>
#include<iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val{v}, left{nullptr}, right{nullptr} {}
};

vector<int> boustrophedonOrder(Node* root) {
    vector<int> ret;
    deque<Node*> Q{root};

    bool LtoR = false;
    while(!Q.empty()) {
        cout << LtoR << endl;

        vector<Node*> currLevel;
        while(!Q.empty()) {
            ret.push_back(Q.front()->val);
            currLevel.push_back(Q.front());
            Q.pop_front();
        }
        for (auto it = currLevel.rbegin(); it != currLevel.rend(); ++it) {
            Node* left = (*it)->left;
            Node* right = (*it)->right;
            if (LtoR) {
                if (left) Q.push_back(left);
                if (right) Q.push_back(right);
            } else {
                if (right) Q.push_back(right);
                if (left) Q.push_back(left);
            }
        }
        LtoR = !LtoR;
    }

    return ret;
}

int main() {
    Node root{1};
    Node n2{2};
    Node n3{3};
    Node n4{4};
    Node n5{5};
    Node n6{6};
    Node n7{7};

    root.left = &n2;
    root.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    vector<int> order = boustrophedonOrder(&root);
    for (int i : order) {
        cout << i << " ";
    }
    cout << endl;
}