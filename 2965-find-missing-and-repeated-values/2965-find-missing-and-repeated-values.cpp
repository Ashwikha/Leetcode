class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>fre(n*n+1,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                fre[grid[i][j]]++;
            }
        }
        int miss=-1,rep=-1;
        for(int i=0;i<fre.size();i++){
            if(fre[i]==0)
            {
                miss=i;
            }
            else if(fre[i]==2){
                rep=i;
            }
        }
        return {rep,miss};
    }
};