#include <bits/stdc++.h>
using namespace std;

bool isRepeatedPattern(long long x) {
    string s = to_string(x);
    int n = s.size();

    for (int k = 1; k <= n/2; k++) {
        if (n % k != 0) continue;

        string block = s.substr(0, k);
        int reps = n / k;

        string built = "";
        for (int i = 0; i < reps; i++)
            built += block;

        if (built == s)
            return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Could not open input.txt\n";
        return 1;
    }

    string line;
    getline(file, line);
    file.close();

    stringstream ss(line);
    string range;

    long long total = 0;

    while (getline(ss, range, ',')) {
        if (range.empty()) continue;

        long long L, R;
        sscanf(range.c_str(), "%lld-%lld", &L, &R);

        for (long long x = L; x <= R; x++) {
            if (isRepeatedPattern(x))
                total += x;
        }
    }

    cout << total << "\n";
    return 0;
}
