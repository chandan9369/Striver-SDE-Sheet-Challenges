bool isCol(vector<vector<int>> board, int i, int j) {
    int c = 0, n = board[i][j];
    for (int k = 0; k < 9; k++) {
        if (board[k][j] == n) {
            c++;
        }
    }
    if (c > 1)
        return false;
    return true;
}
bool isRow(vector<vector<int>> board, int i, int j) {
    int c = 0, n = board[i][j];
    for (int k = 0; k < 9; k++) {
        if (board[i][k] == n) {
            c++;
        }
    }
    if (c > 1)
        return false;
    return true;
}
bool isGrid(vector<vector<int>> board, int i, int j) {
    int c = 0, n = board[i][j];
    int sx = (i / 3) * 3, sy = (j / 3) * 3;
    for (int k = sx; k < sx + 3; k++) {
        for (int p = sy; p < sy + 3; p++) {
            if (board[k][p] == n) {
                c++;
            }
        }
    }
    if (c > 1)
        return false;
    return true;
}
bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                continue;
            }
            if (!(isCol(board, i, j) && isRow(board, i, j) && isGrid(board, i, j))) {
                return false;
            }
        }
    }
    return true;
}