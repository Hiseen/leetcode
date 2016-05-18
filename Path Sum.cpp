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
     bool TravelRecursion(TreeNode* node,int now,int target)
     {
         bool result=false;
         if(node->left)
             result=TravelRecursion(node->left,now+node->val,target);
         if(result)return true;
         if(node->right)
             result=TravelRecursion(node->right,now+node->val,target);
         if(result)return true;
         if(!node->left && !node->right)
             return target==now+node->val;
         return result;
     }
 
 
     bool hasPathSum(TreeNode* root, int sum) {
         if(!root)return false;
         return TravelRecursion(root,0,sum);
     }
 };