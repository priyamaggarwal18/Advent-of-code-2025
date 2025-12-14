#include <bits/stdc++.h>
using namespace std;

typedef struct {
    long long x;
    long long y;
} Point;

bool operator==(const Point& one, const Point& other) {
    return (one.x == other.x) && (one.y == other.y);
}

void build_prefix_sum(vector<vector<long long>>& prefix,
                      const map<long long, long long>& x_sizes,
                      const map<long long, long long>& y_sizes) {
    
    long long N = x_sizes.size();
    long long M = y_sizes.size();

    vector<long long> ordered_x_sizes(N);
    vector<long long> ordered_y_sizes(M);

    int k = 0;
    for (const auto& pair : x_sizes) { ordered_x_sizes[k++] = pair.second; }
    k = 0;
    for (const auto& pair : y_sizes) { ordered_y_sizes[k++] = pair.second; }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) { 
            prefix[i][j] = ordered_x_sizes[i] * ordered_y_sizes[j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i - 1 >= 0) prefix[i][j] += prefix[i - 1][j];
            if (j - 1 >= 0) prefix[i][j] += prefix[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0) prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }
}

bool onBoundary(const Point& query, const vector<Point>& reds) {
    int n = reds.size();
    for (int i = 0; i < n; i++) {
        long long x1 = reds[i].x;
        long long y1 = reds[i].y;
        long long x2 = reds[(i + 1) % n].x;
        long long y2 = reds[(i + 1) % n].y;

        if (y1 == y2 && query.y == y1) {
            long long min_x = min(x1, x2);
            long long max_x = max(x1, x2);
            if (min_x <= query.x && query.x <= max_x) return true;
        }

        if (x1 == x2 && query.x == x1) {
            long long min_y = min(y1, y2);
            long long max_y = max(y1, y2);
            if (min_y <= query.y && query.y <= max_y) return true;
        }
    }
    return false;
}

bool inside(const Point& query, const vector<Point>& reds) {
    double px = (double)query.x + 0.5;
    double py = (double)query.y + 0.5;

    int n = reds.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        double x1 = reds[i].x;
        double y1 = reds[i].y;
        double x2 = reds[(i + 1) % n].x;
        double y2 = reds[(i + 1) % n].y;

        if (x1 == x2) {
            if (px < x1) {
                double min_y = min(y1, y2);
                double max_y = max(y1, y2);

                if (min_y <= py && py < max_y)
                    count++;
            }
        }
    }

    return (count % 2 == 1);
}

bool rectangle_crosses_boundary(long long x1, long long y1,
                                long long x2, long long y2,
                                const vector<Point>& reds) {

    long long min_x = min(x1, x2);
    long long max_x = max(x1, x2);
    long long min_y = min(y1, y2);
    long long max_y = max(y1, y2);

    int n = reds.size();
    for (int i = 0; i < n; i++) {
        long long px1 = reds[i].x;
        long long py1 = reds[i].y;
        long long px2 = reds[(i + 1) % n].x;
        long long py2 = reds[(i + 1) % n].y;

        if (py1 == py2) { 
            long long y = py1;
            if (min_y < y && y < max_y) {
                long long lo = min(px1, px2);
                long long hi = max(px1, px2);
                if (!(hi <= min_x || lo >= max_x)) return true;
            }
        } 
        else {           
            long long x = px1;
            if (min_x < x && x < max_x) {
                long long lo = min(py1, py2);
                long long hi = max(py1, py2);
                if (!(hi <= min_y || lo >= max_y)) return true;
            }
        }
    }

    return false;
}

bool is_valid(long long x1, long long y1, long long x2, long long y2,
              vector<Point>& reds) {
    
    Point corners[4] = {{x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}};
    for (const auto& corner : corners) {
        if (!inside(corner, reds) && !onBoundary(corner, reds)) {
            return false;
        }
    }
    
    if (rectangle_crosses_boundary(x1, y1, x2, y2, reds)) {
        return false;
    }
    
    return true;
}


int main() {
    ifstream file("input.txt");
    string line;

    vector<Point> reds;
    
    if (!file.is_open()) {
        cerr << "Error: Could not open files.txt" << endl;
        return 1;
    }

    while (getline(file, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos) {
            string x_str = line.substr(0, pos);
            string y_str = line.substr(pos + 1);

            try {
                reds.push_back(Point({stoll(x_str), stoll(y_str)}));
            } catch (const exception& e) {
                cerr << "Error parsing line: " << line << endl;
                return 1;
            }
        }
    }
    if (reds.empty()) {
        cerr << "Error: No red tile coordinates found." << endl;
        return 1;
    }

    vector<long long> xs, ys;
    for (const auto& point : reds) {
        xs.push_back(point.x);
        ys.push_back(point.y);
    }
    
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    map<long long, long long> x_sizes;
    map<long long, long long> y_sizes;
    map<long long, long long> x_index;
    map<long long, long long> y_index;

    for (long long i = 0; i < xs.size(); i++) {
        long long compressed_idx = 2 * i;
        x_sizes[compressed_idx] = 1;
        x_index[xs[i]] = compressed_idx;
    }
    for (long long i = 0; i < ys.size(); i++) {
        long long compressed_idx = 2 * i;
        y_sizes[compressed_idx] = 1;
        y_index[ys[i]] = compressed_idx;
    }

    for (long long i = 0; i < xs.size() - 1; i++) {
        long long compressed_idx = 2 * i + 1;
        x_sizes[compressed_idx] = xs[i + 1] - xs[i] - 1;
    }
    for (long long i = 0; i < ys.size() - 1; i++) {
        long long compressed_idx = 2 * i + 1;
        y_sizes[compressed_idx] = ys[i + 1] - ys[i] - 1;
    }

    long long N = x_sizes.size();
    long long M = y_sizes.size();

    vector<vector<long long>> prefix(N, vector<long long>(M, 0));
    build_prefix_sum(prefix, x_sizes, y_sizes);
    
    long long max_area = 0;
    
    for (const auto& u : reds) {
        long long x1 = u.x;
        long long y1 = u.y;
        long long cx1 = x_index.at(x1);
        long long cy1 = y_index.at(y1);

        for (const auto& v : reds) {
            if (u == v) continue;

            long long x2 = v.x;
            long long y2 = v.y;

            if (x1 == x2 || y1 == y2) continue;
            
            if (is_valid(x1, y1, x2, y2, reds)) {
                
                long long min_cx = min(cx1, x_index.at(x2));
                long long max_cx = max(cx1, x_index.at(x2));
                long long min_cy = min(cy1, y_index.at(y2));
                long long max_cy = max(cy1, y_index.at(y2));
                
                long long area = prefix[max_cx][max_cy];
                
                if (min_cx - 1 >= 0) area -= prefix[min_cx - 1][max_cy];
                if (min_cy - 1 >= 0) area -= prefix[max_cx][min_cy - 1];
                if (min_cx - 1 >= 0 && min_cy - 1 >= 0) area += prefix[min_cx - 1][min_cy - 1];
                
                max_area = max(max_area, area);
            }
        }
    }
    
    cout << max_area << endl;
}