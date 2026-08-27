class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        vector<int>l(n);
        vector<int>r(n);
        l[0]=0;
        r[n-1]=0;
        for(int i=1;i<nums.size();i++){
            l[i]=l[i-1]+nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            r[i]=r[i+1]+nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(abs(l[i]-r[i]));
        }
        return ans;
    }
};