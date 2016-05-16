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
     void SumRecursion(TreeNode* node,int now,int &result)
     {
         if(node->left)
             SumRecursion(node->left,now*10+node->val,result);
         if(node->right)
             SumRecursion(node->right,now*10+node->val,result);
         if(!node->left &&!node->right)
             result+=now*10+node->val;
     }
 
     int sumNumbers(TreeNode* root) {
         if(!root)return 0;
         int result=0;
         SumRecursion(root,0,result);
         return result;
         
     }
 };