class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int j=0;
        int x;
        vector<int>temp=arr;
        for(int i=0;i<temp.size()-1;i++){
           if(arr.size()==j){
            break;
           }
           x=temp[i];
            if(x==0){
                arr[j]=x;
                j++;
                if(j<arr.size()) {
                    arr[j]=0;
                    j++;
                }
            }
            else{
                arr[j]=x;
                j++;
            }
            
        }
        
    }
};