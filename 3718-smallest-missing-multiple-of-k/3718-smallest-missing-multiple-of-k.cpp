class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>ans(nums.begin(), nums.end());
        int cur=k;
        while (ans.count(cur)) {
            cur+=k;
        }
        return cur;
    }
};