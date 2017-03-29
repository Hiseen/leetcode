# Definition for a binary tree node.
 # class TreeNode(object):
 #     def __init__(self, x):
 #         self.val = x
 #         self.left = None
 #         self.right = None
 from collections import deque
 class Codec:
     def serialize(self, root):
         """Encodes a tree to a single string.
         :type root: TreeNode
         :rtype: str
         """
         if not root:return '#'
         return '{},'.format(root.val)+self.serialize(root.left)+','+self.serialize(root.right)
             
 
     def deserialize(self, data):
         """Decodes your encoded data to tree.
         :type data: str
         :rtype: TreeNode
         """
         if data=='#':return
         data=deque(data.split(','))
         def helper(data):
             v=data.popleft()
             if v=='#':return
             res=TreeNode(int(v))
             res.left=helper(data)
             res.right=helper(data)
             return res
         return helper(data)
         
         
 
 # Your Codec object will be instantiated and called as such:
 # codec = Codec()
 # codec.deserialize(codec.serialize(root))