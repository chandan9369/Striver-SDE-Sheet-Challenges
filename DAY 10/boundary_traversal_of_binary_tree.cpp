/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void LeftTree(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->left)
    {
        ans.push_back(root->data);
        LeftTree(root->left, ans);
    }
    else if (root->right)
    {
        ans.push_back(root->data);
        LeftTree(root->right, ans);
    }
}
void Leaf(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;
    Leaf(root->left, ans);
    if (!root->left && !root->right)
        ans.push_back(root->data);
    Leaf(root->right, ans);
}
void RightTree(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->right)
    {
        RightTree(root->right, ans);
        ans.push_back(root->data);
    }
    else if (root->left)
    {
        RightTree(root->left, ans);
        ans.push_back(root->data);
    }
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return {};
    if (!root->left && !root->right)
        return {root->data};
    vector<int> ans{root->data};
    LeftTree(root->left, ans);
    Leaf(root, ans);
    RightTree(root->right, ans);
    return ans;
}