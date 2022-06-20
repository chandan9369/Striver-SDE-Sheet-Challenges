// https://www.codingninjas.com/codestudio/problems/920552?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int solve(TreeNode<int> *root, int &diameter) {
    if (!root)    return 0;
    int ld = solve(root->left, diameter);
    int rd = solve(root->right, diameter);

    diameter = max(diameter, ld + rd);
    return 1 + max(ld, rd);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int diameter = 0;
    solve(root, diameter);
    return diameter;
}