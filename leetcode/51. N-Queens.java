/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

class Solution {
       void solve(char board[][],boolean colf[],boolean d1f[],boolean d2f[],int row,List<List<String>> ans,int n){
        if(row==n){
            List<String> curr=new ArrayList<>();
            
            for(int r=0;r<n;r++){
                StringBuilder sb=new StringBuilder();
                for(int c=0;c<n;c++){
                   if(board[r][c]=='Q'){
                      sb.append("Q");
                   }
                    else
                   {
                      sb.append(".");
                   }
                }
                curr.add(sb.toString());
            }
            ans.add(curr);
            return;

            
        }
        for(int col=0;col<n;col++){
            if(colf[col] || d1f[row+col] || d2f[n-1-row+col]) continue;
            colf[col]=d1f[row+col]=d2f[n-1-row+col]=true;
            board[row][col]='Q';
            solve(board,colf,d1f,d2f,row+1,ans,n);
            colf[col]=d1f[row+col]=d2f[n-1-row+col]=false;
            board[row][col]='.';
            
        }
       
    }
    public List<List<String>> solveNQueens(int n) {
    boolean colf[]=new boolean[n];
    boolean d1f[]=new boolean[2*n-1];
     boolean d2f[]=new boolean[2*n-1];
     char board[][] = new char[n][n];
     List<List<String>> ans=new ArrayList<>();
    solve(board,colf,d1f,d2f,0,ans,n);

     return ans;
    }
};