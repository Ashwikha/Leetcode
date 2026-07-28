class Solution {
private int find(int[] leader,int node){
    if(leader[node]!=node){
    leader[node]=find(leader,leader[node]);
    }
    return leader[node];
}
private void join(int[] leader,int left,int right){
      leader[find(leader,left)]=find(leader,right);
}
    public int findCircleNum(int[][] isConnected) {
        int N=isConnected.length;
        
      int[] leader=new int[N+1]; 
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
      int ans=0;
      for(int i=0;i<N;i++){
        if(find(leader,i)==i){
            ans++;
        }
      }
      return ans;
    }
}