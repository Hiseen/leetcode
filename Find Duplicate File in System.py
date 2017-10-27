from collections import defaultdict 
 
class Solution: 
    def findDuplicate(self, paths): 
        """ 
        :type paths: List[str] 
        :rtype: List[List[str]] 
        """ 
        d=defaultdict(list) 
        for i in paths: 
            s=i.split() 
            for j in range(1,len(s)): 
                index=s[j].find('(') 
                d[s[j][index+1:-1]].append(s[0]+"/"+s[j][:index]) 
        res=[] 
        for i in d: 
            if len(d[i])>=2: 
                res.append(d[i]) 
        return res 
                