/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

class Solution {
public:
  bool find(int R,int C,int row,int col,vector<vector<char>> &board,string word,int ni)
  {
    if(ni==word.length())  return true;
    char ch=board[row][col];
    board[row][col]='.';
    int dir[5]={0,-1,0,1,0};
    for(int i=0;i<4;i++)
    {
        int adjR=row+dir[i];
        int adjC=col+dir[i+1];
         if(adjR>=0 && adjC>=0 && adjR<R && adjC<C && board[adjR][adjC]==word[ni])
          {
            bool found=find(R,C,adjR,adjC,board,word,ni+1);
            if(found) return true;
          }
          
    }
    board[row][col]=ch;
    return false;
  }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int R=board.size();
        int C=board[0].size();
       
        for(int row=0;row<R;row++)
        {
            for(int col=0;col<C;col++)
            {
                if(board[row][col]==word[0])
                {
                   bool found=find(R,C,row,col,board,word,1);
                   if(found)
                   return true;
                }
            }
        }
        return false;
    }
};