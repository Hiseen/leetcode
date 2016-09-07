class LRUCache(object):
     
     class DNode:
         def __init__(self,key,val,next=None,prev=None):
             self.key=key
             self.val=val
             self.next=next
             self.prev=prev
 
     def __init__(self, capacity):
         """
         :type capacity: int
         """
         self.cap=capacity
         self.cache={}
         self.DLLhead=None
         self.DLLtail=None
         self.flag=False
 
     def get(self, key):
         """
         :rtype: int
         """
         if key in self.cache:
             temp=self.cache[key]
             self.MoveToHead(temp)
             return temp.val
         else:
             return -1
 
     def set(self, key, value):
         """
         :type key: int
         :type value: int
         :rtype: nothing
         """
         if not self.DLLhead:
             self.DLLhead=self.DNode(key,value)
             self.DLLtail=self.DLLhead
             self.cache[key]=self.DLLhead
         elif key in self.cache:
             temp=self.cache[key]
             temp.val=value
             self.MoveToHead(temp)
         else:
             temp=self.DNode(key,value)
             self.MoveToHead(temp)
             self.cache[key]=temp
             if self.flag or len(self.cache)>self.cap:
                 self.flag=True
                 del self.cache[self.DLLtail.key]
                 self.DLLtail=self.DLLtail.prev
             
     def MoveToHead(self,node):
         if node==self.DLLhead:
             return
         else:
             if node.prev:
                 node.prev.next=node.next
             if node.next:
                 node.next.prev=node.prev
             if self.DLLtail==node:
                 self.DLLtail=self.DLLtail.prev
             if self.DLLhead:
                 node.next=self.DLLhead
                 self.DLLhead.prev=node
         self.DLLhead=node
         node.prev=None
         if not self.DLLtail:
             self.DLLtail=node
             
             
         
         