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
TreeNode<int>*solve(vector<int> & arr, int s, int e) {
    if (s > e) return NULL;
    int mid = (s + e) / 2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = solve(arr, s, mid - 1);
    root->right = solve(arr, mid + 1, e);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return solve(arr, 0, n - 1);
}