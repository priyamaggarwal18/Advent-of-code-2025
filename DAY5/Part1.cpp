#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt");
    
    if (!file.is_open()) {
        cout << "ERROR: input.txt not found!" << endl;
        return 1;
    }
    
    cout << "File opened successfully!" << endl;
    
    vector<pair<long long, long long>> ranges;
    string line;
    while (getline(file, line)) {
        if (line.empty()) break;
        
        stringstream ss(line);
        long long start, end;
        char dash;
        
        if (ss >> start >> dash >> end && dash == '-') {
            ranges.push_back({start, end});
        }
    }
    
    file.close();
    file.open("input.txt");
    
    vector<long long> numbers1D;
    string dummyLine;
    bool readingNumbers = false;
    
    while (getline(file, dummyLine)) {
        if (dummyLine.empty()) {
            readingNumbers = true;
            continue;
        }
        
        if (readingNumbers) {
            stringstream ss(dummyLine);
            long long num;
            while (ss >> num) {
                numbers1D.push_back(num);
            }
        }
    }

    sort(ranges.begin(), ranges.end());
    for(int i=0;i<ranges.size()-1;i++){
        if(ranges[i].second>=ranges[i+1].first){
            ranges[i].second=max(ranges[i].second,ranges[i+1].second);
            ranges.erase(ranges.begin()+i+1);
            i--;
        }
    }

    long count=0;
    for(int i=0;i<numbers1D.size();i++){
        long long num=numbers1D[i];
        for(int j=0;j<ranges.size();j++){
            if(num>=ranges[j].first && num<=ranges[j].second){
                count++;
                break;
            }
        }
    }

    
    cout << count << endl;
    
    return 0;
}
