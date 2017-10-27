class Solution:
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if not t:
            return ""
        res=str(t.val)
        if t.left:
            res+="({})".format(self.tree2str(t.left))
        if t.right:
            if not t.left:
                res+="()"
            res+="({})".format(self.tree2str(t.right))
        return res