class Solution(object):
     def lengthLongestPath(self, input):
         """
         :type input: str
         :rtype: int
         """
         input=input.replace("    ","\t")
         if not "\n" in input:
             if '.' in input:
                 return len(input)
             else:
                 return 0
         s=input.split("\n")
         s=[[i,0] for i in s]
         result=[]
         count=0
         while len(s):
             temp=3
             for i in s:
                 if not i[0].startswith("\t"):
                     temp=len(i[0])
                 i[1]+=temp
             nexts=[]
             for i in s:
                 if i[0].startswith("\t"):
                     nexts.append([i[0][1:],i[1]])
                 elif "." in i[0]:
                     result.append(i[1]+count)
             s=nexts
             count+=1
         return max(result) if len(result) else 0
 
 
         
         