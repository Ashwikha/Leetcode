/*
Given an integer n, find the digit that occurs least frequently in its decimal representation. If multiple digits have the same frequency, choose the smallest digit.

Return the chosen digit as an integer.

The frequency of a digit x is the number of times it appears in the decimal representation of n.
 

Example 1:

Input: n = 1553322

Output: 1

Explanation:

The least frequent digit in n is 1, which appears only once. All other digits appear twice.

Example 2:

Input: n = 723344511

Output: 2

Explanation:

The least frequent digits in n are 7, 2, and 5; each appears only once.

 

Constraints:

1 <= n <= 231​​​​​​​ - 1
 
*/

class Solution {
public:
    int getLeastFrequentDigit(int n) {
    int fre[10]={0};
    while(n!=0){
        int rem=n%10;
        fre[rem]++;
        n/=10;
    }
    int mini=1000;
    int ind;

    for(int i=0;i<10;i++){
        if(fre[i]<mini && fre[i]>0){
            mini=fre[i];
            ind=i;
        }
        
    }
    return ind;
    }
};