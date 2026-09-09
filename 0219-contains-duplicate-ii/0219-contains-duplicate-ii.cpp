class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int j=0;
        for(int i=0;i<nums.size();i++){
           if(mp.count(nums[i]) && abs(j-mp[nums[i]])<=k){
            return 1;
           }
           mp[nums[i]]=j;
           j++;
        }
        return 0;
    }
};