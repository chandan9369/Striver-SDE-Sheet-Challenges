class Solution {
public:
    unordered_map<Node*, Node*> m;
    void  dfs(Node* node) {
        Node* copy = new Node(node->val);
        mp[node] = copy;
        for (auto nbr : node->neighbors) {
            if (m.count(nbr) == 0) {
                dfs(nbr);
            }
            copy->neighbors.push_back(m[nbr]);
        }
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        dfs(node);
        return m[node];
    }
};