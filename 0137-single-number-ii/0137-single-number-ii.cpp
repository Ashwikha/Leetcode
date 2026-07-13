class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>ans;
        for(int i:nums){
            ans[i]++;
        }
        for(int i:nums){
            if(ans[i]==1){
                return i;
            }
        }
        return -1;
    }
};