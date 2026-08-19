class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        
        long fnval=0;
        long sum=0;
        for(int i=0;i<n;i++){
         fnval+=nums[i]*i;
         sum+=nums[i];
        }
        long ans=fnval;
        
        for(int i=n-1;i>0;i--){
            long curr=fnval-(nums[i]*(n-1))+sum-nums[i];
            ans=max(ans,curr);
            fnval=curr;
        }
        return ans;
    }
};