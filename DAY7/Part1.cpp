#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<char>> g;
ll R, C;
set<pair<ll,ll>> vis;
ll splitCount = 0;

void dfs(ll r, ll c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (vis.count({r,c})) return;
    vis.insert({r,c});

    if (g[r][c] == '.') {
        dfs(r + 1, c);
    }
    else if (g[r][c] == '^') {
        splitCount++;
        dfs(r, c - 1);
        dfs(r, c + 1);
    }
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "Unable to open input.txt\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        g.push_back(vector<char>(line.begin(), line.end()));
    }
    file.close();

    R = g.size();
    C = g[0].size();

    ll sr = 0, sc = 0;
    for (ll r = 0; r < R; r++)
        for (ll c = 0; c < C; c++)
            if (g[r][c] == 'S') {
                sr = r;
                sc = c;
            }

    dfs(sr + 1, sc); 

    cout << splitCount << "\n";
    return 0;
}
