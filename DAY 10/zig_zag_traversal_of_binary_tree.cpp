// https://bit.ly/3GrS3g7

/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if (root == NULL) return {};
    vector<int> ans;
    stack<BinaryTreeNode<int> *> s1, s2;

    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            auto node = s1.top();
            s1.pop();

            ans.push_back(node->data);
            if (node->left) s2.push(node->left);
            if (node->right) s2.push(node->right);

        }
        while (!s2.empty()) {
            auto node = s2.top();
            s2.pop();

            ans.push_back(node->data);
            if (node->right) s1.push(node->right);
            if (node->left) s1.push(node->left);
        }
    }

    return ans;

}
