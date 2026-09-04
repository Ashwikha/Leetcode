class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi=0,mini=INT_MAX;
       for(int i=0;i<nums.size();i++){
        maxi=max(nums[i],maxi);
        mini=INT_MAX;
        for(int j=i;j<nums.size();j++){
            mini=min(nums[j],mini);
        }
        if(maxi-mini<=k){
            return i;
        }
       }
        return -1;
    }
};