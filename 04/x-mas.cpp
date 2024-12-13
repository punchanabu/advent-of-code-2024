#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    vector<vector<char> > grid;

    while(getline(cin, line)) {
        vector<char> row;
        for (int i = 0; i < line.length(); i++) {
            row.push_back(line[i]);
        }
        grid.push_back(row);
    }

    int N = grid.size();

    char patterns[4][4] = {
        {'M', 'M', 'S', 'S'},
        {'M', 'S', 'M', 'S'},
        {'S', 'S', 'M', 'M'},
        {'S', 'M', 'S', 'M'},
    };
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool check = grid[i][j] == 'A' 
                            && i + 1 < N 
                            && j + 1 < N 
                            && i - 1 >= 0 
                            && j - 1 >= 0;
            if (check) {
                for (auto pattern : patterns) {
                    if (
                        grid[i-1][j-1] == pattern[0] && 
                        grid[i-1][j+1] == pattern[1] && 
                        grid[i+1][j-1] == pattern[2] && 
                        grid[i+1][j+1] == pattern[3]
                    ) {
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    cout << cnt << endl;

}