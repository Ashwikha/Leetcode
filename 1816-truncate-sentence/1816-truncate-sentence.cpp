class Solution {
public:
    string truncateSentence(string s, int k) {
        string t;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                cnt++;
            }
            if(cnt==k){
                break;
            }
            t+=s[i];
        }
        return t;
    }
};