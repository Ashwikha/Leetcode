/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/


class Solution {
    int diff[]={0,1,0,-1,0};
    private void dfs(int R,int C,int row,int col,int grid[][],int isl[][],int ictr)
    {
        isl[row][col]=ictr;
        for(int i=0;i<4;i++)
        {
            int ar=row+diff[i];
            int ac=col+diff[i+1];
            if(ar>=0 && ar<R && ac>=0 && ac<C && grid[ar][ac]==1 && isl[ar][ac]==0)
            {
                dfs(R,C,ar,ac,grid,isl,ictr);
            }
        }
    }
    public int largestIsland(int[][] grid) 
    {
       int R=grid.length,C=grid[0].length,ictr=1;
       int isl[][] =new int[R][C];
       for(int row=0;row<R;row++)
       {
        for(int col=0;col<C;col++)
        {
          if(grid[row][col]==1 && isl[row][col]==0)
          {
            dfs(R,C,row,col,grid,isl,++ictr);
            
          }
        }
       }
       Map<Integer,Integer> imap=new HashMap<>();  //For each island how many cells present
       for(int row=0;row<R;row++)
       {
        for(int col=0;col<C;col++)
        {
          if(isl[row][col]!=0){
            int curr=imap.getOrDefault(isl[row][col],0);
            imap.put(isl[row][col],curr+1);
          }
        }
       }
       int ans=0;
       for(int ctr=1;ctr<=ictr;ctr++)
       {
        ans=Math.max(ans,imap.getOrDefault(ctr,0));
       }
        for(int row=0;row<R;row++)
        {
         for(int col=0;col<C;col++)
        {
            if(grid[row][col]==0)
            {
                Set<Integer> uniq=new HashSet<>();
                for(int i=0;i<4;i++)
                {
                    int ar=row+diff[i];
                    int ac=col+diff[i+1];
                
            
            if(ar>=0 && ar<R && ac>=0 && ac<C && grid[ar][ac]==1)
            {
                uniq.add(isl[ar][ac]);
            }
         }
        
            int mergedCnt=1;
            for(int island : uniq)
            {
                mergedCnt+=imap.getOrDefault(island,0);

            }
            ans = Math.max(ans, mergedCnt);
            }
          }
        }
        

       return ans;
    }
}