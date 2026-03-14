/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"

 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

class Solution {
public:
    string reverseVowels(string s) {
    int i=0,j=s.size()-1;
      while(i<j)
      {
        char c=tolower(s[i]);
        char d=tolower(s[j]);
        if(!(c=='a'||c=='e'||c=='o'||c=='u'||c=='i'))
        i++;
         if(!(d=='a'||d=='e'||d=='o'||d=='u'||d=='i'))
         j--;

        if(c=='a'||c=='e'||c=='o'||c=='u'||c=='i')
         if(d=='a'||d=='e'||d=='o'||d=='u'||d=='i')
        {
       int temp=s[i];
       s[i]=s[j];
       s[j]=temp;
       i++;
       j--;
         }
      }
      
      return s;
    }
};