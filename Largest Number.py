class Solution:
     # @param {integer[]} nums
     # @return {string}
     def largestNumber(self, nums):
         def c(x,y):
             return int(y+x)-int(x+y)
         temp=[str(i) for i in nums]
         temp=sorted(temp,cmp=c)
         res=''.join(i for i in temp)
         if res[0]=='0':
             return '0'
         else:
             return res
         