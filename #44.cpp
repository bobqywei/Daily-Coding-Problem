#include <vector>
#include <iostream>

using namespace std;

int mergeSort(vector<int> &v, int left, int right) {
    if (right <= left) return 0;

    int inversions = 0;
    int mid = (left + right) / 2;
    vector<int> temp(right - left + 1);

    inversions += mergeSort(v, left, mid);
    inversions += mergeSort(v, mid+1, right);

    int left_index = left;
    int right_index = mid + 1;
    int new_index = 0;

    while ((left_index < mid + 1) && (right_index <= right)) {
        if (v[left_index] <= v[right_index]) {
            temp[new_index++] = v[left_index++];
        } else {
            inversions += (mid + 1) - left_index;            
            temp[new_index++] = v[right_index++];
        }
    }

    while (left_index < mid + 1) {
        temp[new_index++] = v[left_index++];
    }

    while (right_index <= right) {
        temp[new_index++] = v[right_index++];
    }

    for (int i = 0; i < temp.size(); i++) {
        v[i + left] = temp[i];
    }

    return inversions;
}

int getNumberOfInversions(vector<int> &v) {
    return mergeSort(v, 0, v.size()-1);
}

int main() {
    vector<int> v = {5,4,3,2,1};
    cout << getNumberOfInversions(v) << endl;
}
