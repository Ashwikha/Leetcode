class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int fre[101]={0};
        for(int i=0;i<nums.size();i++){
            fre[nums[i]]++;

        }
        for(int i=0;i<nums.size();i++){
            if(fre[nums[i]]==1 && nums[i]%2==0){
                return nums[i];
            }
        }
        return -1;
    }
};