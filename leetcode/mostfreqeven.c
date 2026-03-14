int mostFrequentEven(int* nums, int numsSize) {
   int freq[100001]={0};
   int max=0;
   int val=-1;
   for(int i=0;i<numsSize;i++){
    if(nums[i]%2==0)
      freq[nums[i]]++;

      if(freq[nums[i]]>max){
        max=freq[nums[i]];
        val=nums[i];
      }
      else if(max==freq[nums[i]]&& val>nums[i])
      val=nums[i];
   }
   return val;

   
}