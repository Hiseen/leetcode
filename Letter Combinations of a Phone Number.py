class Solution(object):
     def recur(self,m,now,res,digits):
         if len(digits)==0:
             res.append(now)
         else:
             for i in m[digits[0]]:
                 self.recur(m,now+i,res,digits[1:])
                 
     def letterCombinations(self, digits):
         """
         :type digits: str
         :rtype: List[str]
         """
         if len(digits)==0:
             return []
         m={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz','0':' ','1':'*'}
         result=[]
         self.recur(m,'',result,digits)
         return result