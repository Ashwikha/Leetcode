/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int fre[26]={0};
        int fre1[26]={0};
        for(int i=0;i<s.size();i++)
        {
            fre[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            fre1[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(fre[i]!=fre1[i])
            {
                return 0;
            }
        }
        return 1;
    }
};