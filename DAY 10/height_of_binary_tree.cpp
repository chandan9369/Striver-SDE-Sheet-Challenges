// https://www.codingninjas.com/codestudio/problems/841416?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        else
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// height of binary tree from level order and inorder traversals



int search(vector<int> arr, int s, int e, int key)
{
    for (int i = s; i <= e; i++)
        if (arr[i] == key)
            return i;
    return -1;
}
int solve(vector<int> inorder, vector<int> levelOrder, int s, int e, int height, int n) {
    // Base Case
    if (s > e)
        return 0;

    // Get index of current root in InOrder Traversal
    int index = search(inorder, s, e, levelOrder[0]);

    if (index == -1)
        return 0;

    // elements in Left Subtree
    int lCount = index - s;

    // elements in right Subtree
    int rCount = e - index;


    vector<int> leftLevel(lCount), rightLevel(rCount);

    int lh = 0, rh = 0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = s; j < index; j++) {
            if (levelOrder[i] == inorder[j]) {
                leftLevel[idx++] = levelOrder[i];
                break;
            }
        }
    }

    idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = index + 1; j <= e; j++) {
            if (levelOrder[i] == inorder[j]) {
                rightLevel[idx++] = levelOrder[i];
                break;
            }
        }
    }

    if (lCount > 0)
        lh = solve(inorder, leftLevel, s,
                   index - 1, height, lCount);

    if (rCount > 0)
        rh = solve(inorder, rightLevel,
                   index + 1, e, height, rCount);

    // Current height
    height = max(lh + 1, rh + 1);

    leftLevel.clear();
    rightLevel.clear();

    return height;
}
int Height(vector<int> inorder, vector<int> levelOrder)
{
    return solve(inorder, levelOrder, 0, levelOrder.size() - 1, 0, levelOrder.size());
}
