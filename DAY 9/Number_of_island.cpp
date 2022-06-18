#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

/*
------------------------
        BFS
------------------------
*/
int numIslands( vector<vector<char>> grid)
{
	int n = grid.size();
	int m = grid[0].size();

	int islands = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// case where we have island
			if (grid[i][j] == '1') {
				// do bfs to fill all connected islands to water
				queue<pair<int, int>> q;
				q.push({i, j});
				grid[i][j] = '0';

				while (!q.empty()) {
					auto p = q.front();
					q.pop();

					int x = p.first;
					int y = p.second;

					// traverse all the  directions
					for (int dir = 0; dir < 4; dir++) {
						int newX = x + dx[dir];
						int newY = y + dy[dir];

						// checking boundary conditions
						if (newX >= 0 && newX < n && newY >= 0
						        && newY < m && grid[newX][newY] == '1') {
							grid[newX][newY] = '0';
							q.push({newX, newY});
						}
					}
				}
				// increment the number of islands
				islands++;
			}
		}
	}

	return islands;
}

/*
------------------------
        DFS
------------------------
*/

void floodFill(vector<vector<char>> &grid, int x, int y, int n, int m) {
	// fill current island with water
	grid[x][y] = '0';

	// traverse all the  directions
	for (int dir = 0; dir < 4; dir++) {
		int newX = x + dx[dir];
		int newY = y + dy[dir];

		// checking boundary conditions
		if (newX >= 0 && newX < n && newY >= 0
		        && newY < m && grid[newX][newY] == '1') {
			floodFill(grid, newX, newY, n, m);
		}
	}
}
int numIslands( vector<vector<char>> grid)
{
	int n = grid.size();
	int m = grid[0].size();

	int islands = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// case where we have island
			if (grid[i][j] == '1') {
				floodFill(grid, i, j, n, m);
				// increment the number of islands
				islands++;
			}
		}
	}

	return islands;
}