class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string s;
        int i=0;
        for(string w:words){
            s=words[i];
            reverse(w.begin(),w.end());
            if(s==w)
            return s;
            i++;
        }
        return "";
    }
};