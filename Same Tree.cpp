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
     
     bool recur(TreeNode* pnow,TreeNode *qnow)
     {
         bool res=true;
         if(pnow->left && qnow->left)
             res=recur(pnow->left,qnow->left);
         else if(!(!pnow->left && !qnow->left))
             res=false;
         if(pnow->val!=qnow->val)
             res=false;
         if(pnow->right && qnow->right)
             res*=recur(pnow->right,qnow->right);
         else if(!(!pnow->right && !qnow->right))
             res=false;
         return res;
     }
     
     bool isSameTree(TreeNode* p, TreeNode* q) 
     {
         if(!p && !q)return true;
         if(!p || !q)return false;
         return recur(p,q);
     }
 };