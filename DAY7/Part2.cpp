#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<char>> g;
ll R, C;
map<pair<ll,ll>, ll> memo;

ll countTimelines(ll r, ll c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 1;

    pair<ll,ll> key = {r,c};
    if (memo.count(key)) return memo[key];

    if (g[r][c] == '.') 
        return memo[key] = countTimelines(r + 1, c);
    else if (g[r][c] == '^') 
        return memo[key] = countTimelines(r, c - 1) + countTimelines(r, c + 1);

    return 0;
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

    ll totalTimelines = countTimelines(sr + 1, sc);
    cout << totalTimelines << "\n";

    return 0;
}
