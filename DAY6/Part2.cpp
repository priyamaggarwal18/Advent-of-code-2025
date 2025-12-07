#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) return 1;

    vector<string> rows;
    string line;

    while (getline(file, line)) {
        if (!line.empty()) rows.push_back(line);
    }
    file.close();

    int R = rows.size();
    if (R == 0) return 1;

    int W = 0;
    for (string &s : rows) W = max(W, (int)s.size());
    for (string &s : rows) s += string(W - s.size(), ' ');

    vector<bool> isSeparator(W, false);
    for (int c = 0; c < W; c++) {
        bool allSpaces = true;
        for (int r = 0; r < R; r++) {
            if (rows[r][c] != ' ') {
                allSpaces = false;
                break;
            }
        }
        isSeparator[c] = allSpaces;
    }

    long long grandTotal = 0;
    int c = 0;

    while (c < W) {
        while (c < W && isSeparator[c]) c++;
        if (c >= W) break;

        int start = c;
        while (c < W && !isSeparator[c]) c++;
        int end = c - 1;

        char op = 0;
        for (int col = start; col <= end; col++) {
            char ch = rows[R - 1][col];
            if (ch == '+' || ch == '*') {
                op = ch;
                break;
            }
        }
        if (op == 0) continue;

        vector<long long> numbers;

        for (int col = start; col <= end; col++) {
            string digits;
            for (int r = 0; r < R - 1; r++) {
                char ch = rows[r][col];
                if (isdigit(ch)) digits.push_back(ch);
            }
            if (!digits.empty()) numbers.push_back(stoll(digits));
        }

        long long result = (op == '*') ? 1 : 0;
        if (op == '+') {
            for (long long x : numbers) result += x;
        } else {
            for (long long x : numbers) result *= x;
        }

        grandTotal += result;
    }

    cout << "Grand total = " << grandTotal << "\n";
    return 0;
}
