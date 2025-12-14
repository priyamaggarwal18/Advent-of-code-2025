#include <bits/stdc++.h>
using namespace std;

struct Shape {
    vector<string> pattern;
    int filled;
};

struct Region{
    int w, h;
    vector<int> counts;
};

typedef vector<pair<int, int>> Coords;
typedef vector<vector<int>> Grid;

Coords parseShape(const vector<string>& pattern) {
    Coords cells;
    for (int r = 0; r < pattern.size(); r++) {
        for (int c = 0; c < pattern[r].length(); c++) {
            if (pattern[r][c] == '#') {
                cells.push_back({r, c});
            }
        }
    }
    return cells;
}

Coords normalize(const Coords& shape) {
    if (shape.empty()) return shape;
    
    int minR = shape[0].first, minC = shape[0].second;
    for (const auto& p : shape) {
        minR = std::min(minR, p.first);
        minC = std::min(minC, p.second);
    }
    
    Coords normalized;
    for (const auto& p : shape) {
        normalized.push_back({p.first - minR, p.second - minC});
    }
    sort(normalized.begin(), normalized.end());
    return normalized;
}

Coords rotate90(const Coords& shape) {
    Coords rotated;
    for (const auto& p : shape) {
        rotated.push_back({p.second, -p.first});
    }
    return normalize(rotated);
}

Coords flipH(const Coords& shape) {
    Coords flipped;
    for (const auto& p : shape) {
        flipped.push_back({p.first, -p.second});
    }
    return normalize(flipped);
}

vector<Coords> getVariants(const Coords& shape) {
    set<Coords> uniqueVariants;
    Coords current = shape;
    
    for (int i = 0; i < 4; i++) {
        uniqueVariants.insert(normalize(current));
        uniqueVariants.insert(normalize(flipH(current)));
        current = rotate90(current);
    }
    
    return vector<Coords>(uniqueVariants.begin(), uniqueVariants.end());
}

bool canPlace(const Grid& grid, const Coords& shape, int row, int col, int w, int h) {
    for (const auto& p : shape) {
        int r = row + p.first;
        int c = col + p.second;
        if (r < 0 || r >= h || c < 0 || c >= w || grid[r][c] != 0) {
            return false;
        }
    }
    return true;
}

void place(Grid& grid, const Coords& shape, int row, int col, int id) {
    for (const auto& p : shape) {
        grid[row + p.first][col + p.second] = id;
    }
}

void unplaceShape(Grid& grid, const Coords& shape, int row, int col) {
    for (const auto& p : shape) {
        grid[row + p.first][col + p.second] = 0;
    }
}

bool solve(Grid& grid, const vector<Coords>& presents, int w, int h, int idx = 0) {
    if (idx == presents.size()) return true;
    
    const Coords& shape = presents[idx];
    
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (canPlace(grid, shape, r, c, w, h)) {
                place(grid, shape, r, c, idx + 1);
                if (solve(grid, presents, w, h, idx + 1)) {
                    return true;
                }
                unplaceShape(grid, shape, r, c);
            }
        }
    }
    return false;
}

bool canFitPresents(int w, int h, const vector<int>& counts, const vector<Shape>& shapes) {
    vector<Coords> baseShapes;
    vector<vector<Coords>> allVariants;
    
    for (const auto& shape : shapes) {
        baseShapes.push_back(parseShape(shape.pattern));
        allVariants.push_back(getVariants(baseShapes.back()));
    }
    
    vector<int> presentTypes;
    int totalCells = 0;
    for (int i = 0; i < counts.size(); i++) {
        for (int j = 0; j < counts[i]; j++) {
            presentTypes.push_back(i);
            totalCells += shapes[i].filled;
        }
    }
    
    if (presentTypes.empty()) return true;
    if (totalCells > w * h) return false;

    vector<int> variantIndices(presentTypes.size(), 0);
    
    function<bool(int)> tryVariants = [&](int presIdx) -> bool {
        if (presIdx == presentTypes.size()) {
            Grid grid(h, vector<int>(w, 0));
            vector<Coords> selectedVariants;
            for (int i = 0; i < presentTypes.size(); i++) {
                selectedVariants.push_back(allVariants[presentTypes[i]][variantIndices[i]]);
            }
            return solve(grid, selectedVariants, w, h);
        }
        
        int shapeType = presentTypes[presIdx];
        for (int v = 0; v < allVariants[shapeType].size(); v++) {
            variantIndices[presIdx] = v;
            if (tryVariants(presIdx + 1)) return true;
        }
        return false;
    };
    
    return tryVariants(0);
}

int main(){
    ifstream file("input.txt");
    string line;

    vector<Shape> shapes;
    vector<Region> regions;

    while(getline(file, line)){
        if(line.empty()) continue;

        if (line.back() == ':' && isdigit(line[0])) {
            Shape shape;
            shape.filled = 0;
            shape.pattern.clear();
            string pattern_line;
            for (int i = 0; i < 3; i++) { // Had to hardcode this bit
                if (!getline(file, pattern_line)) break;

                shape.pattern.push_back(pattern_line);
                shape.filled += count(
                    pattern_line.begin(),
                    pattern_line.end(),
                    '#'
                );
            }
            shapes.push_back(shape);
        }

        if (line.find('x') != string::npos && line.find(':') != string::npos) {
            Region r;
            int pos1 = line.find('x');
            int pos2 = line.find(':');

            r.w = stoi(line.substr(0, pos1));
            r.h = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            istringstream ss(line.substr(pos2 + 2));
            int count;
            while(ss >> count) r.counts.push_back(count);
            
            regions.push_back(r);
        }
    }

    long long totalCount = 0;
    for(const auto& region : regions){
        long long totalHash = 0;
        for(int i = 0; i < region.counts.size(); i++){
            totalHash += shapes[i].filled * region.counts[i];
        }
        if(totalHash > region.w * region.h) continue;

        if (canFitPresents(region.w, region.h, region.counts, shapes)) {
            totalCount++;
        }
    }
    
    cout << totalCount << endl;
    
    return 0;
}