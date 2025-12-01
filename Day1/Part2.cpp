#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    int dial = 50;
    int countZero = 0;

    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        char dir = line[0];
        int dist = stoi(line.substr(1));

        if (dir == 'R') {
            for (int i = 0; i < dist; i++) {
                dial = (dial + 1) % 100;
                if (dial == 0) countZero++;
            }
        } 
        else if (dir == 'L') {
            for (int i = 0; i < dist; i++) {
                dial = (dial - 1 + 100) % 100;
                if (dial == 0) countZero++;
            }
        }
    }

    cout << "The password to open the door is: " << countZero << endl;
    return 0;
}
