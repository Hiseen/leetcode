class Solution(object):
     def recursive_func(self,l,n,h,m,index):
         if h<12 and m<60:
             if n==0:
                 l.append("{}:{:0>2}".format(h,m))
             else:
                 for i in range(index,10):
                     if i<4:
                         self.recursive_func(l,n-1,h+2**i,m,i+1)
                     else:
                         a=i-4;
                         self.recursive_func(l,n-1,h,m+2**a,i+1)
             
     
     
     
     def readBinaryWatch(self, num):
         """
         :type num: int
         :rtype: List[str]
         """
         if num>=9:return []
         l=[]
         self.recursive_func(l,num,0,0,0)
         return l
         