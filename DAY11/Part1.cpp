#include <bits/stdc++.h>
using namespace std;

static inline string trim(const string &s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

long long dfsCount(
    const string &node,
    unordered_map<string, vector<string>> &g,
    unordered_set<string> &onPath
) {
    if (node == "out") return 1;

    if (!g.count(node) || g[node].empty()) return 0;

    onPath.insert(node);
    long long total = 0;

    for (auto &nbr : g[node]) {
        if (!onPath.count(nbr)) {
            total += dfsCount(nbr, g, onPath);
        }
    }

    onPath.erase(node);
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, vector<string>> graph;

    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Could not open input.txt\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        line = trim(line);
        if (line.empty()) continue;

        size_t colon = line.find(':');
        if (colon == string::npos) continue;

        string node = trim(line.substr(0, colon));
        string rest = trim(line.substr(colon + 1));

        stringstream ss(rest);
        string tok;
        while (ss >> tok) graph[node].push_back(tok);
    }

    unordered_set<string> onPath;
    long long result = dfsCount("you", graph, onPath);

    cout << result << "\n";
    return 0;
}
