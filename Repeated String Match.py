class Solution:
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        temp=A
        res=1
        lent=len(A)
        nowlen=lent
        maxlen=max(len(B),lent)*3
        while(nowlen<maxlen):
            if B in temp: return res
            temp+=A
            nowlen+=lent
            res+=1
        return -1