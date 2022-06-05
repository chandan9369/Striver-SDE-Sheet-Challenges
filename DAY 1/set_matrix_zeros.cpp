#include <bits/stdc++.h>
void makeZeros(vector<vector<int>>& matrix, int row, int col) {
    for (int i = 0; i < matrix[row].size(); i++) {
        matrix[row][i] = 0;
    }
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][col] = 0;
    }
}
void setZeros(vector<vector<int>>& matrix) {
    vector<pair<int, int>> pairs;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                pairs.push_back({i, j});
            }
        }
    }
    for (auto pos : pairs) {
        int row = pos.first;
        int col = pos.second;
        makeZeros(matrix, row, col);
    }
}