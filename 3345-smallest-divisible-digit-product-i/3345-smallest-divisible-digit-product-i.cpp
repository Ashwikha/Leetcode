class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n<=t)
        {
            return t;
        }
        int sum;
       for(int i=n;i<n*2;i++){
           sum=1;
           int x=i;
           while(x!=0){
               sum*=x%10;
               x/=10;
               
           }
           if(sum%t==0){
               return i;
           }
           
       } 
       return n;
    }
};