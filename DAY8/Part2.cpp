#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    int components;
    DSU(int n) : parent(n), size(n, 1), components(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        components--;
        return true;
    }
};

long long dist2(const array<int,3>& a, const array<int,3>& b) {
    long long dx = a[0] - b[0];
    long long dy = a[1] - b[1];
    long long dz = a[2] - b[2];
    return dx*dx + dy*dy + dz*dz;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    vector<array<int,3>> pts;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        int x, y, z;
        ss >> x >> y >> z;
        pts.push_back({x, y, z});
    }

    int n = pts.size();
    if (n == 0) {
        cout << "No input!\n";
        return 0;
    }

    //generate all edges
    vector<tuple<long long,int,int>> edges;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            edges.emplace_back(dist2(pts[i], pts[j]), i, j);
        }
    }

    //sort by distance
    sort(edges.begin(), edges.end(),
        [](auto& a, auto& b){
            return get<0>(a) < get<0>(b);
        });
    
    
    DSU dsu(n);
    long long answer = 0;

    for (auto &e : edges) {
        int u = get<1>(e);
        int v = get<2>(e);

        //merge only if they are in different components
        if (dsu.unite(u, v)) {
            //check if this merge creates a single component
            if (dsu.components == 1) {
                answer = (long long)pts[u][0] * pts[v][0];
                break;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
