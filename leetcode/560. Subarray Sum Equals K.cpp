/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int csum=0,count=0;
        map<int,int> m;
        m[0]=1;
        for(int v:nums)
        {
            csum+=v;
            if(m.find(csum-k)!=m.end()){
                count+=m[csum-k];
            }
            if(m.find(csum)==m.end()) 
            m[csum]=1;
            else
            m[csum]++;
        }
        return count;
    }
};