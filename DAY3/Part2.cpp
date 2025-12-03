#include <bits/stdc++.h>
using namespace std;

string pickBest(const string &s, int k) {
    int n = s.size();
    int remove = n - k;
    vector<char> st;

    for (char c : s) {
        while (!st.empty() && remove > 0 && st.back() < c) {
            st.pop_back();
            remove--;
        }
        st.push_back(c);
    }

    while (remove > 0) {
        st.pop_back();
        remove--;
    }

    string res;
    for (int i = 0; i < k; i++) res.push_back(st[i]);
    return res;
}

int main() {
    ifstream input("input.txt");
    long long total = 0;
    string s;

    while (getline(input, s)) {
        if (s.empty()) continue;

        string best = pickBest(s, 12);

        long long val = stoll(best);
        total += val;
    }

    cout << "Total output joltage: " << total << endl;
    return 0;
}
