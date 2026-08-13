class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int fre[501]={0};
        for(int i=0;i<nums.size();i++){
            fre[nums[i]]++;
        }
        for(int i=1;i<501;i++){
            if(fre[i]%2!=0)
            {
                return 0;
            }
        }
        return 1;
    }
};