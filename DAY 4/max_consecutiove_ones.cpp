class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int large = 0;
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                large = max(c, large);
                c = 0;
            }
            else {
                c++;
            }
        }
        return max(large, c);
    }
};