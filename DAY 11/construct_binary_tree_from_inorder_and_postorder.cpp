// https://bit.ly/3qrzumM
class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* rec(vector<int>& inorder, vector<int>& postorder, int l, int r, int &idx) {
        if (l > r) {
            return nullptr;
        }
        int el = postorder[idx];
        int pos = mp[el];
        TreeNode* root = new TreeNode(el);
        idx--;
        root->right =  rec(inorder, postorder, pos + 1, r, idx);
        root->left =  rec(inorder, postorder, l, pos - 1, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int idx = postorder.size() - 1;
        return rec(inorder, postorder, 0, inorder.size() - 1, idx);
    }
};