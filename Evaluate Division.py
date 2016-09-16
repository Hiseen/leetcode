class Solution(object):
     def travel(self,g,v,start,end):
         result,explore,explored={i:v[(start,i)] for i in g[start]},g[start][:],set([start])
         if end in result:return result[end]
         while len(explore):
             n=explore.pop()
             if not n in explored:
                 explored.add(n)
                 if n in g:
                     explore.extend(g[n])
                     for i in g[n]:
                         if (n,i) in v:
                             temp=result[n]
                             result[i]=temp*v[(n,i)]
                             if i==end:
                                 return result[i]
         return -1.0
         
                 
     
        
     def calcEquation(self, equations, values, query):
         """
         :type equations: List[List[str]]
         :type values: List[float]
         :type query: List[List[str]]
         :rtype: List[float]
         """
         g={}
         vg={}
         for i in range(len(equations)):
             eq=equations[i]
             vg[tuple(eq)]=values[i]
             vg[(eq[1],eq[0])]=1/float(values[i])
             if eq[1] in g:
                 g[eq[1]].append(eq[0])
             else:
                 g[eq[1]]=[eq[0]]
             if eq[0] in g:
                 g[eq[0]].append(eq[1])
             else:
                 g[eq[0]]=[eq[1]]
         result=[]
         for i in query:
             if (not i[0] in g) or (not i[1] in g):
                 result.append(-1.0)
             elif i[0]==i[1]:
                 result.append(1.0)
             else:
                 result.append(self.travel(g,vg,i[0],i[1]))
         return result
                 