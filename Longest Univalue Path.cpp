/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(int& m,TreeNode* root,int num)
    {
       int res1=0;
       int res2=0;
       if(root->left)
           res1=helper(m,root->left,root->val);
       if(root->right) 
           res2=helper(m,root->right,root->val);
       if(res1+res2>m)m=res1+res2;
       if(root->val==num)return max(res1,res2)+1;
       else return 0;
    }
    
    
    
    
    
    int longestUnivaluePath(TreeNode* root) {
        int m=0;
        if(root)helper(m,root,0);
        return m;
    }
};