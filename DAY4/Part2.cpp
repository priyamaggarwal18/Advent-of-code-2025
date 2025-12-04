#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream input("input.txt");
    vector<string> grid;
    string s;

    while (getline(input, s)) {
        if (!s.empty()) grid.push_back(s);
    }

    int rows = grid.size();
    int cols = grid[0].size();

    int totalRemoved = 0;

    while (true) {
        vector<pair<int,int>> toRemove;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] != '@') continue;

                int cnt = 0;

                if (i > 0 && grid[i-1][j] == '@') cnt++;
                if (i < rows-1 && grid[i+1][j] == '@') cnt++;
                if (j > 0 && grid[i][j-1] == '@') cnt++;
                if (j < cols-1 && grid[i][j+1] == '@') cnt++;
                if (i > 0 && j > 0 && grid[i-1][j-1] == '@') cnt++;
                if (i > 0 && j < cols-1 && grid[i-1][j+1] == '@') cnt++;
                if (i < rows-1 && j > 0 && grid[i+1][j-1] == '@') cnt++;
                if (i < rows-1 && j < cols-1 && grid[i+1][j+1] == '@') cnt++;

                if (cnt < 4) toRemove.push_back({i, j});
            }
        }

        if (toRemove.empty()) break;

        for (auto &p : toRemove) {
            grid[p.first][p.second] = '.';
        }

        totalRemoved += toRemove.size();
    }

    cout << totalRemoved << endl;
}
