class Solution {
public:
    int secondsBetweenTimes(string s, string e) {
        int a1=s[0]*10+s[1];
        int a2=s[3]*10+s[4];
        int a3=s[6]*10+s[7];

        int b1=e[0]*10+e[1];
        int b2=e[3]*10+e[4];
        int b3=e[6]*10+e[7];

        int ans1=a1*60*60+a2*60+a3;
        int ans2=b1*60*60+b2*60+b3;
        return ans2-ans1;
    }
};