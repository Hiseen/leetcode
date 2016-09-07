class Solution(object):
     
     def validate(self,data):
         temp=bin(data[0])
         if len(temp)<10:
             return True,data[1:]
         elif temp[2:4]=='10':
             return False,None
         else:
             count=-1
             for i in temp[2:]:
                 if i=='1':
                     count+=1
                 elif i=='0':
                     break
             if 1+count>len(data):
                 return False,None
             ndata=data[1:1+count]
             for i in ndata:
                 if len(bin(i))!=10 or bin(i)[2:4]!='10':
                     return False,None
             return True,data[1+count:]
     
     def validUtf8(self, data):
         """
         :type data: List[int]
         :rtype: bool
         """
         while True:
             res,data=self.validate(data)
             if res==False:
                 return False
             if data==[]:
                 return True
         
         
         
         
         