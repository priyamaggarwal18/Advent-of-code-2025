#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
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
        pts.push_back({x,y,z});
    }

    int n = pts.size();
    if (n == 0) {
        cout << "No input!\n";
        return 0;
    }

    //generate all edges
    vector<tuple<long long,int,int>> edges;
    edges.reserve((long long)n * (n-1) / 2);

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

    //DSU to find connected components for first 1000 edges
    DSU dsu(n);
    int LIMIT = 1000;
    LIMIT = min(LIMIT, (int)edges.size());

    for (int i = 0; i < LIMIT; i++) {
        auto &e = edges[i];
        int u = get<1>(e);
        int v = get<2>(e);
        dsu.unite(u, v);
    }

   //get all connected component sizes
    unordered_map<int,int> comp;
    for (int i = 0; i < n; i++) {
        comp[dsu.find(i)]++;
    }

    vector<int> sizes;
    for (auto &p : comp) sizes.push_back(p.second);

    sort(sizes.rbegin(), sizes.rend()); //to sort in descending order

    //if fewer than 3 circuits, multiply whatever exists
    long long ans = 1;
    for (int i = 0; i < min(3, (int)sizes.size()); i++) {
        ans *= sizes[i];
    }

    cout << ans << "\n";
    return 0;
}
