class Solution {
    public int smallestIndex(int[] nums) {
        int sum=0;
        for(int i=0;i<nums.length;i++){
            while(nums[i]!=0){
                int rem=nums[i]%10;
                sum+=rem;
                nums[i]/=10;
            }
            if(sum==i){
                return i;
            }
            sum=0;
        }
        return -1;
    }
}