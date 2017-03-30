class Solution(object):
     def licenseKeyFormatting(self, S, K):
         """
         :type S: str
         :type K: int
         :rtype: str
         """
         S=S.replace('-','').upper()
         l=len(S)
         if K>l:return S
         i=l%K
         if i:
             res=S[:i]+'-'
         else:
             res=''
         while i<l-K:
             res+=S[i:i+K]+'-'
             i+=K
         return res+S[i:i+K]
             