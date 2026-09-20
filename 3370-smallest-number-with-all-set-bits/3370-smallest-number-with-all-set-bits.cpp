class Solution {
public:
    int smallestNumber(int n) {
        if (n==1) return 1;
        
        for(int i=n+1;i<=n*n;i++){
            if((i & (i - 1)) == 0){
                return i-1;
            }
        }
        return n;
    }
};