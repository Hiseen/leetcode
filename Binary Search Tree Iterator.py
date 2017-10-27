# Definition for a  binary tree node 
# class TreeNode(object): 
#     def __init__(self, x): 
#         self.val = x 
#         self.left = None 
#         self.right = None 
 
class BSTIterator(object): 
    def travel(self,root): 
        self.l.append(root.val) 
        self.max_index+=1 
        if root.left: 
            self.travel(root.left) 
        if root.right: 
            self.travel(root.right) 
             
    def __init__(self, root): 
        """ 
        :type root: TreeNode 
        """ 
        self.l=[] 
        self.max_index=0 
        if root:self.travel(root) 
        self.l=sorted(self.l) 
        self.index=0 
 
    def hasNext(self): 
        """ 
        :rtype: bool 
        """ 
        return self.index<self.max_index 
         
    def next(self): 
        """ 
        :rtype: int 
        """ 
        result=self.l[self.index] 
        self.index+=1 
        return result 
         
         
         
 
# Your BSTIterator will be called like this: 
# i, v = BSTIterator(root), [] 
# while i.hasNext(): v.append(i.next())