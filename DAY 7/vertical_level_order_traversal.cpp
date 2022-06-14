/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return {};
    queue<pair<TreeNode<int> *, int>> q;
    map<int, vector<TreeNode<int>*>> m;
    m[0].push_back(root);
    q.push({root, 0});
    while (!q.empty())
    {
        int n = q.size();
        int i = 0;
        while (i < n)
        {
            pair<TreeNode<int> *, int> p = q.front();
            if (p.first->left != NULL)
            {
                q.push({p.first->left, p.second - 1});
                m[p.second - 1].push_back(p.first->left);
            }
            if (p.first->right != NULL)
            {
                q.push({p.first->right, p.second + 1});
                m[p.second + 1].push_back(p.first->right);
            }
            q.pop();
            i++;
        }
    }
    for (auto x : m) {
        for (auto v : x.second)
            ans.push_back(v->data);
    }
    return ans;
}