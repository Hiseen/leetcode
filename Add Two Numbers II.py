# Definition for singly-linked list.
 # class ListNode(object):
 #     def __init__(self, x):
 #         self.val = x
 #         self.next = None
 
 class Solution(object):
     def addTwoNumbers(self, l1, l2):
         """
         :type l1: ListNode
         :type l2: ListNode
         :rtype: ListNode
         """
         i1,i2=0,0
         while l1:
             i1*=10
             i1+=l1.val
             l1=l1.next
         while l2:
             i2*=10
             i2+=l2.val
             l2=l2.next
         t=str(i1+i2)
         res=ListNode(int(t[0]))
         temp=res
         for i in t[1:]:
             temp.next=ListNode(int(i))
             temp=temp.next
         return res
         