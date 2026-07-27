class Solution {
public:
    int characterReplacement(string s, int k) {
        int fre[26]={0};
        int maxi=0;
        int ans=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            fre[s[i]-'A']++;
            maxi=max(maxi,fre[s[i]-'A']);
            while((i-j+1)-maxi>k)
            {
              
                fre[s[j]-'A']--;
                j++;

            }
           ans=max(ans,i-j+1);
        }
        return ans;
    }
};