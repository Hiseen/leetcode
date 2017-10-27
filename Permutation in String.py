from collections import defaultdict
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s2)<len(s1):
            return False
        elif s2==s1:
            return True
        m=defaultdict(int)
        for i in s1:
            m[i]+=1
        m2=defaultdict(int)
        l=len(s1)
        for i in range(l):
            m2[s2[i]]+=1
        if l==len(s2):
            return all(m[j]==m2[j] for j in m)
        for i in range(l,len(s2)):
            if all(m[j]==m2[j] for j in m):
                return True
            else:
                m2[s2[i-l]]-=1
                m2[s2[i]]+=1
        return all(m[j]==m2[j] for j in m)
            