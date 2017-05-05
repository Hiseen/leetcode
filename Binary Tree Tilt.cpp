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
 
 
     int recur(TreeNode* root,int& s)
     {
         if(!root)
             return 0;
         int l=recur(root->left,s);
         int r=recur(root->right,s);
         s+=abs(l-r);
         return l+r+root->val;
     }
 
     int findTilt(TreeNode* root) {
         int s=0;
         recur(root,s);
         return s;
     }
 };