class Solution(object):
     def isValidSudoku(self, board):
         """
         :type board: List[List[str]]
         :rtype: bool
         """
         sets=[[set() for i in range(9)]for j in range(3)]
         for i in range(9):
             for j in range(9):
                 temp=board[i][j]
                 if temp!='.':
                     if temp in sets[0][i]:
                         return False
                     else:
                         sets[0][i].add(temp)
                     if temp in sets[1][j]:
                         return False
                     else:
                         sets[1][j].add(temp)
                     if temp in sets[2][int(i/3)*3+int(j/3)]:
                         return False
                     else:
                         sets[2][int(i/3)*3+int(j/3)].add(temp)
         return True