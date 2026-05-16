/*
You are given a positive integer n.

Return the integer obtained by removing all zeros from the decimal representation of n.

 

Example 1:

Input: n = 1020030

Output: 123

Explanation:

After removing all zeros from 1020030, we get 123.

Example 2:

Input: n = 1

Output: 1

Explanation:

1 has no zero in its decimal representation. Therefore, the answer is 1.

 

Constraints:

1 <= n <= 1015
 */


class Solution {
public:
    long long removeZeros(long long n) {
         string ans;
         string s=to_string(n);
         for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                ans+=s[i];
            }
         }
        return stol(ans);
    }
};