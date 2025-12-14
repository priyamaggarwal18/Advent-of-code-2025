#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("input.txt");
    vector<pair<long long,long long>> redTiles;
    long long x, y;
    while (fin >> x) {
        fin.ignore(); // skip comma
        fin >> y;
        redTiles.push_back({x, y});
    }

    long long maxArea = 0;
    int n = redTiles.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            long long x1 = redTiles[i].first;
            long long y1 = redTiles[i].second;
            long long x2 = redTiles[j].first;
            long long y2 = redTiles[j].second;

            long long width = abs(x2 - x1)+1;
            long long height = abs(y2 - y1)+1;

            long long area = width * height;
            maxArea = max(maxArea, area);
        }
    }

    cout << "Largest rectangle area: " << maxArea << endl;
    return 0;
}
