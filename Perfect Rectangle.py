class Solution(object):
     def isRectangleCover(self, rectangles):
         """
         :type rectangles: List[List[int]]
         :rtype: bool
         """
         temp=set(tuple(i) for i in rectangles)
         if len(temp) !=len(rectangles):
             return False
         d={}
         area=0
         for i in rectangles:
             p=[(i[0],i[1]),(i[0],i[3]),(i[2],i[3]),(i[2],i[1])]
             for j in p:
                 if not j in d:
                     d[j]=1
                 else:
                     d[j]+=1
             area+=(i[3]-i[1])*(i[2]-i[0])
         count=0
         min_x,min_y,max_x,max_y=None,None,None,None
         for i in d:
            if d[i]==1:
                count+=1
            if min_x==None or min_x>i[0]:
                min_x=i[0]
            if max_x==None or max_x<i[0]:
                max_x=i[0]
            if min_y==None or min_y>i[1]:
                min_y=i[1]
            if max_y==None or max_y<i[1]:
                max_y=i[1]
         return count==4 and area==(max_x-min_x)*(max_y-min_y)
             