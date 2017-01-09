class Solution(object):
     def calculate(self, s):
         """
         :type s: str
         :rtype: int
         """
         _precedence={
              '-':1,'+':1,
              '*':2,'/':2
              }
         stack=[]
         final_stack=[]
         i=0
         while i<len(s):
             char=s[i]
             if char==' ':
                 i+=1
             elif char.isdigit():
                 end=i+1
                 while end<len(s) and s[end].isdigit():
                     end+=1
                 final_stack.append(int(s[i:end]))
                 i=end
             elif char in _precedence:
                 while len(stack) and _precedence[stack[-1]]>=_precedence[char]:
                     final_stack.append(stack.pop())
                 stack.append(char)
                 i+=1
             else:
                 i+=1
         stack.reverse()
         final_stack.extend(stack)
         stack=[]
         for i in final_stack:
             if not i in _precedence:
                 stack.append(i)
             else:
                 temp=stack.pop()
                 op=i
                 if op=='+':
                     stack.append(temp+stack.pop())
                 elif op=='-':
                     stack.append(stack.pop()-temp)
                 elif op=='*':
                     stack.append(temp*stack.pop())
                 else:
                     stack.append(int(stack.pop()/temp))
         return stack[0]
                 
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         