#include <bits/stdc++.h>
using namespace std;

int main() {

    ifstream inputFile("input.txt");
    int dial = 50;         
    int countZeroPass = 0;   
    string line;

    while (getline(inputFile, line)) {
        
        if (line.empty()) continue;
        char direction = line[0];  
        int distance = stoi(line.substr(1));
        if (direction == 'L') {
            dial -= distance;
            while (dial < 0) {
                dial += 100;
            }
        } else if (direction == 'R') {
            dial += distance;
            while (dial >= 100){
                dial -= 100;
            }
        } else {
            cerr << "Invalid direction in input: " << direction << endl;
            return 1;
        }

        if (dial == 0) {
            countZeroPass++;
        }
    }

    inputFile.close();

    cout << "The password to open the door is: " << countZeroPass << endl;

    return 0;
}
