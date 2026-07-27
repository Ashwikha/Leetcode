class Solution {

private:
 int find(vector<int>& leader,int node){
    if(leader[node]!=node){
        leader[node]=find(leader,leader[node]);
    }
    return leader[node];
}

void join(vector<int>& leader,int left,int right){
    leader[find(leader,right)]=find(leader,left);
}

public:
    int latestDayToCross(int R, int C, vector<vector<int>>& cells) {
        vector<int> leader(R * C + 3); // 1 based index + 2 imaginary nodes
        vector<bool>water(R*C+2,false);
        for(int i=0;i<R*C+2;i++){
            leader[i]=i; 
        }
        int days=0;
        vector<vector<int>>diff{{-1,0},{1,1},{-1,-1},{0,1},{1,0},{0,-1},{1,-1},{-1,1}};  //left,right,top left,top right ,etc
        for(const auto& cell:cells){
            int row=cell[0],col=cell[1];
            row--;    //as 0 indexing we subtract 1
            col--;
            water[row*C+col+1]=true;
            for(const auto& d:diff){
                int ar=row+d[0],ac=col+d[1];
                if(ar>=0 && ar<R && ac>=0 && ac<C && water[ar*C+ac+1]){ //checking if valid
                    join(leader,row*C+col+1,ar*C+ac+1);
                }
            }
                if(col==0){             //assigns water to first imaginary cell
                    join(leader,0,row*C+col+1);
                }
                else if(col==C-1){       // assigns ater to last imaginary cell
                    join(leader,row*C+col+1,R*C+1);
                }
                if(find(leader,0)==find(leader,R*C+1)){  //checks if both imaginary nodes are same 
                    break;
                }
                days++;
            }
        return days;
    }
};