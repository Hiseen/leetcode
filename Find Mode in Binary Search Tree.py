# Definition for a binary tree node.
 # class TreeNode(object):
 #     def __init__(self, x):
 #         self.val = x
 #         self.left = None
 #         self.right = None
 
 class Solution(object):
     def findMode(self, root):
         """
         :type root: TreeNode
         :rtype: List[int]
         """
         if not root:return []
         from collections import defaultdict
         def InOrder(root,m):
             if root.left:
                 InOrder(root.left,m)
             m[root.val]+=1
             if root.right:
                 InOrder(root.right,m)
         m=defaultdict(int)
         InOrder(root,m)
         max=0
         for i in m:
             if m[i]>max:
                 max=m[i]
         res=[]
         for i in m:
             if m[i]==max:
                 res.append(i)
         return res
             