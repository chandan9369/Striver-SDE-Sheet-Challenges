// https://www.codingninjas.com/codestudio/problems/796002?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL) return {};
    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            BinaryTreeNode<int> * curr = q.front();
            q.pop();
            ans.push_back(curr->val);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return ans;
}