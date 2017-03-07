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
 
     void recur(TreeNode* root,int& maxdepth,int& maxleft,int& val,int depth,int left)
     {
         if(depth>maxdepth)
         {
             maxdepth=depth;
             val=root->val;
         }
         else if(depth==maxdepth && left>=maxleft)
         {
             maxleft=left;
             val=root->val;
         }
         if(root->right)
             recur(root->right,maxdepth,maxleft,val,depth+1,left);
         if(root->left)
             recur(root->left,maxdepth,maxleft,val,depth+1,left+1);
     }
 
 
     int findBottomLeftValue(TreeNode* root) {
         int maxd=0;
         int maxl=0;
         int val=0;
         recur(root,maxd,maxl,val,1,0);
         return val;
     }
 };