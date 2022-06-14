/************************************************************

    Following is the TreeNode class structure:

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
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if (root == NULL)
        return {};
    queue<pair<TreeNode<int> *, int>> q;
    map<int, int> m;
    m[0] = root->val;
    q.push({root, 0});
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            auto curr = q.front();
            q.pop();
            if (m[curr.second] == 0) {
                m[curr.second] = curr.first->val;
            }
            if (curr.first->left != NULL) {
                q.push({curr.first->left, curr.second - 1});
            }
            if (curr.first->right != NULL) {
                q.push({curr.first->right, curr.second + 1});
            }
        }
    }
    for (auto x : m) {
        ans.push_back(x.second);
    }
    return ans;
}
