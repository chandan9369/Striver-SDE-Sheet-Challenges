// https://bit.ly/3fqsvnA
// https://leetcode.com/problems/balanced-binary-tree/
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
int BT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if (root == NULL) return 0;

    int lh = BT(root->left);
    if (lh == -1) return -1;

    int rh = BT(root->right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;
    else
        return max(lh, rh) + 1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    if (BT(root) >= 0) return true;
    else return false;
}