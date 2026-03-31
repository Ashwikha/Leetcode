/*
Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

 

Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
 

Constraints:

1 <= nums.length <= 15
-100 <= nums[i] <= 100
*/

class Solution {
public:
         void recursive(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        
            if (temp.size()>=2){
            ans.push_back(temp);
        
        }
             unordered_set<int> used;      //avoids duplicate
            for(int i=ind;i<nums.size();i++){
             if(used.count(nums[i])) continue;        // skips duplicates
            
               


        if(temp.empty() || nums[i]>=temp.back()){
        used.insert(nums[i]);
        temp.push_back(nums[i]);
        recursive(i+1, nums, temp, ans);
        temp.pop_back();
       
        }
            }
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        recursive(0, nums, temp, ans);
        return ans;
    }
};