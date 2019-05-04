#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void replace_adjacent( 
	char from, 
	char to, 
	pair<int, int> curr,
	vector<vector<char>>& image, 
	vector<vector<bool>>& visited)
{
	int rows = image.size();
	int cols = image[0].size();

	// iterate through 9 adjacent values
	for (int i = -1; i < 2; i++) {
		int y = curr.first + i;
		if (y >= 0 && y < rows) {
			
			for (int j = -1; j < 2; j++) {
				int x = curr.second + j;
				// check if position was already visited
				if (x >= 0 && x < cols && !visited[y][x]) {
					// set the position as visited
					visited[y][x] = true;
					// replace all adjacent pixels
					if (image[y][x] == from) {
						image[y][x] = to;
						replace_adjacent(from, to, make_pair(y, x), image, visited);
					}
				}
			}
		}
	}
}

void fill_color(vector<vector<char>>& image, char color, pair<int, int> loc) {
	// fill matrix with false values
	vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
	char prev_color = image[loc.first][loc.second];
	if (prev_color != color) 
		replace_adjacent(prev_color, color, loc, image, visited);
}

int main() {
	vector<vector<char>> image = {{'B','B','W'},
								  {'W','W','W'},
								  {'W','W','W'},
								  {'B','B','B'}};

	fill_color(image, 'G', make_pair(2, 2));

	for (vector<char> v : image) {
		for (char c : v) {
			cout << c << " ";
		}
		cout << endl;
	}
}