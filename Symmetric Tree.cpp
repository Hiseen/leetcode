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
 
     bool compare(TreeNode* left,TreeNode* right)
     {
         if(!left && !right)return true;
         if(!left || !right)return false;
         bool result=left->val==right->val;
         if(left->left && right->right)
             result=result && compare(left->left,right->right);
         else if(left->left || right->right)
             result=false;
         if(left->right && right->left)
             result=result && compare(right->left,left->right);
         else if(left->right || right->left)
             result=false;
         return result;
     }
     
     bool isSymmetric(TreeNode* root) {
         if(!root)return true;
         return compare(root->left,root->right);
     }
 };