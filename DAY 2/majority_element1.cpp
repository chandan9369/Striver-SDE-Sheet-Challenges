class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto x : nums) {
            m[x]++;
        }
        int ans = -1;
        for (auto x : m) {
            if (x.second > (nums.size() / 2)) {
                ans = x.first;
                break;
            }
        }
        return ans;
    }
};