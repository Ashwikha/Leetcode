/* Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1 
*/


class Solution {
    int rowdiff[]={-1,0,1,0};
     int coldiff[]={0,1,0,-1};
    public int longestIncreasingPath(int[][] matrix) {
    
     int R=matrix.length;
     int C=matrix[0].length;
     int ans=1;
     int[][] path=new int[R][C];
     for(int r=0;r<R;r++)
     {
        for(int c=0;c<C;c++)
        {
            if(path[r][c]==0)
            {
                path[r][c]=dfs(r,c,R,C,matrix,path);
                ans=Math.max(ans,path[r][c]);
            }
        }
        
     }   
     return ans;
    }

     private int dfs(int r,int c,int R,int C,int[][] matrix,int[][] path)
     {
        if(path[r][c]!=0)
        {
            return path[r][c];
        }
        int maxpath=0;
        for(int di=0;di<4;di++)
        {
            int adjR=r+rowdiff[di];
            int adjC=c+coldiff[di];
          if(adjR>R-1 || adjC>C-1 || adjR<0 || adjC<0)
          {
            continue;
          }
          if(matrix[adjR][adjC]>matrix[r][c])
          {
            int currpath=dfs(adjR,adjC,R,C,matrix,path);
            maxpath=Math.max(maxpath,currpath);
          }
        }
        path[r][c]=maxpath+1;
        return path[r][c];
     
    }
}