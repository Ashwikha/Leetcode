class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int c=0;
        int sum1=0,sum2=0;
        sum1=nums[0];
        for(int i:nums){
            sum2+=i;
        }
        sum2=sum2-sum1;
        for(int i=0;i<nums.size()-1;i++){
            if((sum1-sum2)%2==0){
                c++;
            }
            if(i+1<nums.size()-1){
            sum1+=nums[i+1];
            sum2-=nums[i+1];
            }
        }
        return c;
    }
};