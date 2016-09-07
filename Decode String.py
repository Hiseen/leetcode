class Solution(object):
     def decodeString(self, s):
         """
         :type s: str
         :rtype: str
         """
         while '[' in s:
             s=re.sub(r'(\d+)\[([a-z]+)\]',lambda x:int(x.group(1))*x.group(2),s)
         return s