class Solution {
public:
    int maxProduct(int n) {
        vector<int>a;
        while(n!=0){
            int rem=n%10;
            a.push_back(rem);
            n/=10;
        }
        sort(a.begin(),a.end());
        return a[a.size()-1]*a[a.size()-2];
    }
};