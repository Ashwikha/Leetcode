class Solution {
public:
    string removeTrailingZeros(string num) {
        string s;
        int cnt=0;
        for(int i=num.size()-1;i>=0;i--){
            if(num[i]=='0')
            cnt++;
            else
            break;
        }
        for(int i=0;i<num.size()-cnt;i++){
            s+=num[i];
        }
        return s;
    }
};