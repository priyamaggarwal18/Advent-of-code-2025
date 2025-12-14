#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> g;
unordered_map<string, unordered_map<string, long long>> memo;

string key(bool dacVisited, bool fftVisited) {
    return string(1, dacVisited ? '1' : '0') + string(1, fftVisited ? '1' : '0');
}

long long dfs(const string &node, bool dacVisited, bool fftVisited) {
    if (node == "dac") dacVisited = true;
    if (node == "fft") fftVisited = true;

    string state = key(dacVisited, fftVisited);
    if (memo[node].count(state)) return memo[node][state];

    if (node == "out") return memo[node][state] = (dacVisited && fftVisited ? 1 : 0);

    long long totalPaths = 0;
    for (auto &neighbor : g[node]) {
        totalPaths += dfs(neighbor, dacVisited, fftVisited);
    }

    return memo[node][state] = totalPaths;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        size_t colon = line.find(':');
        if (colon == string::npos) continue;

        string node = line.substr(0, colon);
        string rest = line.substr(colon + 1);

        stringstream ss(rest);
        string neighbor;
        while (ss >> neighbor) {
            g[node].push_back(neighbor);
        }
    }

    long long result = dfs("svr", false, false);
    cout << result << "\n";
}
