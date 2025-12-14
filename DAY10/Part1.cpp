#include <bits/stdc++.h>

using namespace std;

bool parse_machine_input(const string& line, vector<int>& target_lights, vector<vector<int>>& toggle_matrix) {
    target_lights.clear();
    toggle_matrix.clear();

    size_t start_bracket = line.find('[');
    size_t end_bracket = line.find(']');
    if (start_bracket == string::npos || end_bracket == string::npos) return false;

    string diagram = line.substr(start_bracket + 1, end_bracket - start_bracket - 1);
    for (char c : diagram) {
        target_lights.push_back(c == '#');
    }
    int num_lights = target_lights.size();

    size_t pos = end_bracket + 1;
    while (pos < line.size()) {
        size_t start_paren = line.find('(', pos);
        size_t end_paren = line.find(')', pos);

        if (start_paren == string::npos || end_paren == string::npos) break;

        string schematic = line.substr(start_paren + 1, end_paren - start_paren - 1);
        vector<int> button_effects(num_lights, 0);

        stringstream ss(schematic);
        string segment;
        while (getline(ss, segment, ',')) {
            try {
                int light_index = stoi(segment);
                if (light_index >= 0 && light_index < num_lights) {
                    button_effects[light_index] = 1;
                }
            } catch (...) { }
        }

        toggle_matrix.push_back(button_effects);
        pos = end_paren + 1;
    }

    if (!toggle_matrix.empty()) {
        int num_buttons = toggle_matrix.size();
        vector<vector<int>> A(num_lights, vector<int>(num_buttons));
        for (int j = 0; j < num_buttons; ++j) {
            for (int i = 0; i < num_lights; ++i) {
                A[i][j] = toggle_matrix[j][i];
            }
        }
        toggle_matrix = A;
    }

    return true;
}

bool simplify_system_mod_2(vector<vector<int>>& augmented_matrix) {
    if (augmented_matrix.empty() || augmented_matrix[0].empty()) return true;

    int num_rows = augmented_matrix.size();
    int num_cols = augmented_matrix[0].size();
    int num_variables = num_cols - 1;
    int pivot_row = 0;

    for (int j = 0; j < num_variables && pivot_row < num_rows; ++j) {
        int pivot_i = pivot_row;
        while (pivot_i < num_rows && augmented_matrix[pivot_i][j] == 0) {
            pivot_i++;
        }

        if (pivot_i < num_rows) {
            swap(augmented_matrix[pivot_row], augmented_matrix[pivot_i]);

            for (int i = 0; i < num_rows; ++i) {
                if (i != pivot_row && augmented_matrix[i][j] == 1) {
                    for (int k = j; k < num_cols; ++k) {
                        augmented_matrix[i][k] = augmented_matrix[i][k] ^ augmented_matrix[pivot_row][k];
                    }
                }
            }
            pivot_row++;
        }
    }

    for (int i = pivot_row; i < num_rows; ++i) {
        if (augmented_matrix[i][num_variables] == 1) {
            return false;
        }
    }

    return true;
}

long long find_min_presses_for_machine(const vector<int>& target_lights, const vector<vector<int>>& toggle_matrix) {
    int num_lights = target_lights.size();
    if (num_lights == 0) return 0;
    int num_buttons = toggle_matrix[0].size();
    if (num_buttons == 0) return (all_of(target_lights.begin(), target_lights.end(), [](int x){ return x == 0; }) ? 0 : -1);

    vector<vector<int>> M(num_lights, vector<int>(num_buttons + 1));
    for (int i = 0; i < num_lights; ++i) {
        for (int j = 0; j < num_buttons; ++j) {
            M[i][j] = toggle_matrix[i][j];
        }
        M[i][num_buttons] = target_lights[i];
    }

    if (!simplify_system_mod_2(M)) {
        return -1; 
    }

    vector<int> pivot_cols;
    vector<int> free_cols;
    int pivot_row = 0;
    
    for (int j = 0; j < num_buttons; ++j) {
        bool is_pivot = false;
        if (pivot_row < num_lights && M[pivot_row][j] == 1) {
             int first_one_col = -1;
             for(int k=0; k<num_buttons; ++k) {
                 if(M[pivot_row][k] == 1) {
                     first_one_col = k;
                     break;
                 }
             }
             if(first_one_col == j) {
                 is_pivot = true;
             }
        }

        if (is_pivot) {
            pivot_cols.push_back(j);
            pivot_row++;
        } else {
            free_cols.push_back(j);
        }
    }
    
    int num_free = free_cols.size();
    int rank = pivot_cols.size();
    
    vector<int> particular_solution(num_buttons, 0);
    for (int i = 0; i < rank; ++i) {
        int pivot_j = pivot_cols[i];
        particular_solution[pivot_j] = M[i][num_buttons]; 
    }
    
    vector<vector<int>> null_space_basis;
    for (int f = 0; f < num_free; ++f) {
        vector<int> null_vector(num_buttons, 0);
        int free_j = free_cols[f];
        null_vector[free_j] = 1; 
        
        for (int i = 0; i < rank; ++i) {
            int pivot_j = pivot_cols[i];
            null_vector[pivot_j] = M[i][free_j];
        }
        null_space_basis.push_back(null_vector);
    }
    
    long long min_presses = num_buttons + 1;

    for (long long i = 0; i < (1LL << num_free); ++i) {
        vector<int> current_solution = particular_solution;
        long long current_presses = 0;

        for (int f = 0; f < num_free; ++f) {
            if ((i >> f) & 1) {
                for (int j = 0; j < num_buttons; ++j) {
                    current_solution[j] = current_solution[j] ^ null_space_basis[f][j];
                }
            }
        }

        for (int val : current_solution) {
            current_presses += val;
        }

        min_presses = min(min_presses, current_presses);
    }

    return min_presses;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream infile("input.txt");
    if (!infile.is_open()) {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    string line;
    long long total_min_presses = 0;

    cout << "Starting machine initialization...\n";

    while (getline(infile, line)) {
        if (line.empty()) continue;

        vector<int> target_lights;
        vector<vector<int>> toggle_matrix;

        if (parse_machine_input(line, target_lights, toggle_matrix)) {
            long long min_presses = find_min_presses_for_machine(target_lights, toggle_matrix);

            if (min_presses == -1) {
                cout << "Machine failed to initialize (no solution found).\n";
            } else {
                total_min_presses += min_presses;
            }
        }
    }

    cout<< total_min_presses << "\n";

    return 0;
}