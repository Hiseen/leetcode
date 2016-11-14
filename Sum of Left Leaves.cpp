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
     int sumOfLeftLeaves(TreeNode* root) 
     {
         return recur(root,false);
         
     }
     
     int recur(TreeNode* root,bool flag)
     {
         if(!root)return 0;
         if(flag && !root->left && !root->right)return root->val;
         int result=0;
         if(root->left)
             result+=recur(root->left,true);
         if(root->right)
             result+=recur(root->right,false);
         return result;
     }
     
     
 };