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

    sort(ranges.begin(), ranges.end());
    for(int i=0;i<ranges.size()-1;i++){
        if(ranges[i].second>=ranges[i+1].first){
            ranges[i].second=max(ranges[i].second,ranges[i+1].second);
            ranges.erase(ranges.begin()+i+1);
            i--;
        }
    }
    long long count=0;
    for(int i=0;i<ranges.size();i++){
        count+=ranges[i].second-ranges[i].first+1;
    }
    cout<<"Total numbers covered: "<<count<<endl;

    
    return 0;
}
