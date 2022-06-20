// https://bit.ly/3fqOif3
class Solution {
public:
    int index = 0;
    unordered_map<int, int> m;
    TreeNode*solve(vector<int>& pre, int s, int e) {
        if (s > e) {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[index]);
        index++;
        int key_index = m[root->val];
        root->left = solve(pre, s, key_index - 1);
        root->right = solve(pre, key_index + 1, e);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for (int i = 0; i < in.size(); i++) {
            m[in[i]] = i;
        }
        return solve(pre, 0, in.size() - 1);
    }
};

