class Solution {
public:
    string reverseByType(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]>='a' && s[i]<='z' && s[j]>='a' && s[j]<='z'){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(s[i]>='a' && s[i]<='z'){
                j--;
            }
            else
            {
                i++;
            }
        }
         i=0,j=s.size()-1;
        while(i<j){
            if(!(s[i]>='a' && s[i]<='z') && !(s[j]>='a' && s[j]<='z')){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!(s[i]>='a' && s[i]<='z')){
                j--;
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};