class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>neg;
        vector<int>pos;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
               neg.push_back(nums[i]);
            }else
            {
               pos.push_back(nums[i]);
            }
        }
        int i=0;
        int j=0;
        int k=0;
        while(i!=pos.size() || j!=neg.size()){
            if(i<pos.size()){
                nums[k++]=pos[i++];
            }
            if(j<neg.size()){
                nums[k++]=neg[j++];
            }
        }
        return nums;
    }
};