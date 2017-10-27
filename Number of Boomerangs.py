class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        from collections import defaultdict
        def dis(a,b):
            return abs(a[0]-b[0])**2+abs(a[1]-b[1])**2
        m={}
        res=0
        for i,j in enumerate(points):
            m[i]=defaultdict(int)
            for k in points:
                if j!=k:
                    m[i][dis(j,k)]+=1
            for p in m[i]:
                t2=m[i][p]
                if t2>=2:
                    res+=t2*(t2-1)
        return res
            
        