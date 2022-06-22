int dislikedColor;
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;
void floodFill(int x, int y, int color, vector<vector<int>> &grid) {
    grid[x][y] = color;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == dislikedColor) {
            floodFill(xx, yy, color, grid);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    n = image.size();
    m = image[0].size();

    dislikedColor = image[x][y];
    if (dislikedColor == newColor) return image;
    floodFill(x, y, newColor, image);
    return image;
}