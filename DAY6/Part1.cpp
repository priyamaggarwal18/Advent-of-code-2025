#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "Unable to open input.txt\n";
        return 1;
    }

    vector<vector<string>> data;
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<string> row;
        string token;

        while (ss >> token) row.push_back(token);
        data.push_back(row);
    }

    file.close();

    int rows = data.size();
    if (rows < 2) {
        cout << "Not enough rows.\n";
        return 1;
    }

    // The last row is operators
    int cols = data[rows - 1].size();

    // Ensure all rows have exactly 'cols' columns
    for (int r = 0; r < rows - 1; r++) {
        if ((int)data[r].size() < cols) {
            data[r].resize(cols, "0");
        }
    }

    vector<long long> results(cols, 0);

    for (int i = 0; i < cols; i++) {
        string ops = data[rows - 1][i]; 
        
        if (ops == "+") {
            long long col_sum = 0;
            for (int r = 0; r < rows - 1; r++) {
                col_sum += stoll(data[r][i]);
            }
            results[i] = col_sum;
        } else if (ops == "*") {
            long long col_prod = 1;
            for (int r = 0; r < rows - 1; r++) {
                col_prod *= stoll(data[r][i]);
            }
            results[i] = col_prod;
        } else {
            cout << "Unknown operator '" << ops << "' in column " << i << endl;
            return 1;
        }
    }

    long long grand_total = 0;
    for (long long val : results) {
        grand_total += val;
    }

    cout << "Grand total: " << grand_total << endl;
    return 0;
}
