/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    int ans = 0;
    if (root == NULL) return ans;
    // Write your code here.
    queue<TreeNode<int>*>q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        ans = max(ans, n);
        for (int i = 0; i < n; i++) {
            TreeNode<int>* curr = q.front();
            q.pop();
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
    return ans;
}