#include <bits/stdc++.h>

using namespace std;

void horizontal_search(int &cnt, vector<vector<char> > &grid) {
    int N = grid.size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j + 3 < N && grid[i][j] == 'X' && grid[i][j+1] == 'M' && grid[i][j+2] == 'A' && grid[i][j+3] == 'S') {
                cnt++;
            }

            if (j - 3 >= 0 && grid[i][j] == 'X' && grid[i][j-1] == 'M' && grid[i][j-2] == 'A' && grid[i][j-3] == 'S') {
                cnt++;
            }
        }
    }
}

void vertical_search(int &cnt, vector<vector<char> > &grid) {
    int N = grid.size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j + 3 < N && grid[j][i] == 'X' && grid[j+1][i] == 'M' && grid[j+2][i] == 'A' && grid[j+3][i] == 'S') {
                cnt++;
            }

            if (j - 3 >= 0 && grid[j][i] == 'X' && grid[j-1][i] == 'M' && grid[j-2][i] == 'A' && grid[j-3][i] == 'S') {
                cnt++;
            }
        }
    }
}

void diagonal_search(int &cnt, vector<vector<char> > &grid) {
    int N = grid.size();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 3 < N && j + 3 < N && grid[i][j] == 'X' && grid[i+1][j+1] == 'M' && grid[i+2][j+2] == 'A' && grid[i+3][j+3] == 'S') {
                cnt++;
            }

            if (i - 3 >= 0 && j - 3 >= 0 && grid[i][j] == 'X' && grid[i-1][j-1] == 'M' && grid[i-2][j-2] == 'A' && grid[i-3][j-3] == 'S') {
                cnt++;
            }
            
            if (i + 3 < N && j - 3 >= 0 && grid[i][j] == 'X' && grid[i+1][j-1] == 'M' && grid[i+2][j-2] == 'A' && grid[i+3][j-3] == 'S') {
                cnt++;
            }

            if (i - 3 >= 0 && j + 3 < N && grid[i][j] == 'X' && grid[i-1][j+1] == 'M' && grid[i-2][j+2] == 'A' && grid[i-3][j+3] == 'S') {
                cnt++;
            }
        }
    }
}



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

    int cnt = 0;

    horizontal_search(cnt, grid);
    vertical_search(cnt, grid);
    diagonal_search(cnt, grid);

    cout << cnt << endl;

}