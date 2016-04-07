class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        l1=version1.split('.')
        l1=[int(i) for i in l1]
        l2=version2.split('.')
        l2=[int(i) for i in l2]
        if len(l1)>len(l2):
            l2.extend([0 for i in range(len(l1)-len(l2))])
        elif len(l2)>len(l1):
            l1.extend([0 for i in range(len(l2)-len(l1))])
        for i in range(len(l1)):
            if l1[i]>l2[i]:
                return 1
            elif l1[i]<l2[i]:
                return -1
        return 0
            
        