class Solution {
private:

int find(vector<int>& leader,int node){
    if(leader[node]!=node){
        leader[node]=find(leader,leader[node]);
    }
    return leader[node];
}

void join(vector<int>& leader,int left,int right){
    leader[find(leader,left)]=find(leader,right);
}

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N=isConnected.size();
        vector<int>leader(N+1);
        int ans=0;
        for(int i=0;i<N;i++){
            leader[i]=i;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(isConnected[i][j]==1){
                join(leader,i,j);
            }
        }
        }
        for(int i=0;i<N;i++){
            if(find(leader,i)==i){
                ans++;
            }
        }
        return ans;
    }
};