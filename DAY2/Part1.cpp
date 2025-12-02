#include <bits/stdc++.h>
using namespace std;

bool isDoubleNumber(long long x) {
    string s = to_string(x);
    int n = s.size();

    if (n % 2 != 0) return false;

    string first = s.substr(0, n/2);
    string second = s.substr(n/2);

    return first == second;
}

int main(){
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open input.txt\n";
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
            if (isDoubleNumber(x)) {
                total += x;
            }
        }
    }

    cout << total << "\n";
    return 0;
}
