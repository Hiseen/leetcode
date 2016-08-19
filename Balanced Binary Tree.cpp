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
     int countHeight(TreeNode* root,bool& result)
     {
         if(!root)
             return 0;
         else
         {
             int l=countHeight(root->left,result);
             int r=countHeight(root->right,result);
             if(abs(l-r)>1)result=false;
             return 1+std::max(l,r);
         }
     }
 
     bool isBalanced(TreeNode* root) {
         bool result=true;
         countHeight(root,result);
         return result;
     }
 };