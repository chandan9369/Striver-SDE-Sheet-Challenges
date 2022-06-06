#include <bits/stdc++.h>
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & arr, int m, int n, int key) {
    if (arr[0][0] > key || arr[m - 1][n - 1] < key) {
        return 0;
    }
    int i = 0, j = n - 1;
    while (i <= m - 1 && j >= 0) {
        if (arr[i][j] == key) {
            return 1;
        }
        else if (arr[i][j] > key) {
            j--;
        }
        else {
            i++;
        }
    }
    return 0;
}