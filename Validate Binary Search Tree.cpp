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
 
     int getlmax(TreeNode* root)
     {
         if(root->right)
             return getlmax(root->right);
         else
             return root->val;
     }
 
     int getrmin(TreeNode* root)
     {
         if(root->left)
             return getrmin(root->left);
         else
             return root->val;
     }
 
     void validate(TreeNode* root,int fatherval,bool lor,bool& result)
     {
         int val=root->val;
          if(root->left)
             validate(root->left,val,true,result);
         if(root->right)
             validate(root->right,val,false,result);
         if(lor)//current node is father's left node
         {
             if(fatherval<=val || (root->right && root->right->val>=fatherval) || getlmax(root)>=fatherval)
                 result=false;
         }
         else
         {
             if(fatherval>=val || (root->left && root->left->val<=fatherval) || getrmin(root)<=fatherval)
                 result=false;
         }
     }
 
     bool isValidBST(TreeNode* root) {
         if(!root)return true;
         bool result=true;
         if(root->left)
             validate(root->left,root->val,true,result);
         if(root->right)
             validate(root->right,root->val,false,result);
         return result;
     }
 };
 