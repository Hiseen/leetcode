class Solution(object):
     def wordBreak(self, s, wordDict):
         """
         :type s: str
         :type wordDict: Set[str]
         :rtype: bool
         """
         record=set()
         record.add(0)
         lens=len(s)
         for i in range(1,lens+1):
             for j in wordDict:
                 lenj=len(j)
                 if (i-lenj) in record and i-lenj>=0 and s[i-lenj:i] in wordDict:
                     record.add(i)
                     break
         print(record)
         return lens in record