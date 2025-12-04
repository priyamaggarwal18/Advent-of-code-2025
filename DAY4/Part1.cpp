#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream input("input.txt");
    vector<string> grid;
    string s;
    int total=0;

    while (getline(input, s)) {
        if (s.empty()) continue;
        grid.push_back(s);
    }

    int rows = grid.size();
    int cols = grid[0].size();

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int countneighbors=0;
            char current =grid[i][j];
            if(current=='@' ){
                if(i>0 && grid[i-1][j]=='@') countneighbors++; //up
                if(i<rows-1 && grid[i+1][j]=='@') countneighbors++; //down
                if(j>0 && grid[i][j-1]=='@') countneighbors++; //left
                if(j<cols-1 && grid[i][j+1]=='@') countneighbors++; //right
                if(i>0 && j>0 && grid[i-1][j-1]=='@') countneighbors++; //up-left
                if(i>0 && j<cols-1 && grid[i-1][j+1]=='@') countneighbors++; //up-right
                if(i<rows-1 && j>0 && grid[i+1][j-1]=='@') countneighbors++; 
                if(i<rows-1 && j<cols-1 && grid[i+1][j+1]=='@') countneighbors++; 
                if(countneighbors<4){
                    total+=1;
                }
            }
        }
    }

    cout << "Total " << total << endl;
    return 0;
}