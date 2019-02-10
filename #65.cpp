#include <iostream>
#include <vector>

using namespace std;

void spiralPrint(vector<vector<int>> &m) {
    int top = 0;
    int bottom = m.size()-1;
    int left = 0;
    int right = m[0].size()-1;

    int x = 0;
    int y = 0;
    bool end = false;

    cout << m[y][x] << endl;

    while (!end) {
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                if (x == right) {
                    end = true;
                    break;
                }

                while (x < right) {
                    x++;
                    cout << m[y][x] << endl;
                }
                top++;
            } else if (i == 1) {
                if (y == bottom) {
                    end = true;
                    break;
                }

                while (y < bottom) {
                    y++;
                    cout << m[y][x] << endl;
                }
                right--;
            } else if (i == 2) {
                if (x == left) {
                    end = true;
                    break;
                }

                while (x > left) {
                    x--;
                    cout << m[y][x] << endl;
                }
                bottom--;
            } else if (i == 3) {
                if (y == top) {
                    end = true;
                    break;
                }

                while (y > top) {
                    y--;
                    cout << m[y][x] << endl;
                }
                left++;
            }
        }
    }
}

int main() {
    vector<vector<int>> v{{1,2,3,4},
                          {5,6,7,8},
                          {9,10,11,12},
                          {13,14,15,16}};
    spiralPrint(v);
}