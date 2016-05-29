class Solution(object):
     def getHint(self, secret, guess):
         """
         :type secret: str
         :type guess: str
         :rtype: str
         """
         m={}
         b,c=0,0
         s=set()
         for i in secret:
             if i in m:
                 m[i]+=1
             else:
                 m[i]=1
         for i in range(len(guess)):
             if guess[i]==secret[i]:
                 m[guess[i]]-=1
                 b+=1
                 s.add(i)
         for i in {i for i in range(len(guess))}-s:
             if guess[i] in m and m[guess[i]]>0:
                 m[guess[i]]-=1
                 c+=1
         return '{}A{}B'.format(b,c)
             