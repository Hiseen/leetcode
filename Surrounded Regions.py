class Solution(object):
     def dfs(self,board,i,j,max_i,max_j):
         if i>=0 and i<max_i and j>=0 and j<max_j and board[i][j]=='O':
             board[i][j]='C'
             if i == 0: self.dfs(board,i+1, j,max_i,max_j)
             elif j == 0: self.dfs(board,i, j+1,max_i,max_j)
             elif i == max_i-1: self.dfs(board,i-1, j,max_i,max_j)
             elif j == max_j-1: self.dfs(board,i,j-1,max_i,max_j)
             else:
                 self.dfs(board,i+1,j,max_i,max_j)
                 self.dfs(board,i-1,j,max_i,max_j)
                 self.dfs(board,i,j+1,max_i,max_j)
                 self.dfs(board,i,j-1,max_i,max_j)
     
     
     
     def solve(self, board):
         """
         :type board: List[List[str]]
         :rtype: void Do not return anything, modify board in-place instead.
         """
         max_i=len(board)
         if max_i==0:return
         max_j=len(board[0])
         if max_i<=2 or max_j<=2:
             return
         else:
             for i in range(max_i):
                 if board[i][0]=='O':
                     self.dfs(board,i,0,max_i,max_j)
             for i in range(max_i):
                 if board[i][max_j-1]=='O':
                     self.dfs(board,i,max_j-1,max_i,max_j)
             for i in range(1,max_j-1):
                 if board[0][i]=='O':
                     self.dfs(board,0,i,max_i,max_j)
             for i in range(1,max_j-1):
                 if board[max_i-1][i]=='O':
                     self.dfs(board,max_i-1,i,max_i,max_j)
             
             for i in range(max_i):
                 for j in range(max_j):
                     if board[i][j]=='C':
                         board[i][j]='O'
                     else:
                         board[i][j]='X'
                         
                         