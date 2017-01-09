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
 
 
     int maxPathSumHelper(TreeNode* root,int& max)
     {
         int l=0,r=0;
         if(root->left)
             l=maxPathSumHelper(root->left,max);
         if(root->right)
             r=maxPathSumHelper(root->right,max);
         if(!l&&!r)
         {
             if(root->val>max)
                 max=root->val;
             return root->val;
         }
         if(!(l&&r))
             if(l)
             {
                 if(l<0)
                 {
                     if(root->val>max)
                         max=root->val;
                     return root->val;
                 }
                 else
                 {
                     if(l>max)
                         max=l;
                     return l+root->val;
                 }
             }
             else
             {
                  if(r<0)
                 {
                     if(root->val>max)
                         max=root->val;
                     return root->val;
                 }
                 else
                 {
                     if(r>max)
                         max=r;
                     return r+root->val;
                 }
             }
         if(l+r+root->val>max)
             max=l+r+root->val;
         if(l>r)
         {
             if(l<0)
             {
                 if(root->val>max)
                     max=root->val;
                 return root->val;
             }
             else
             {
                 if(l>max)
                     max=l;
                 return l+root->val;
             }
         }
         else
         {
             if(r<0)
             {
                 if(root->val>max)
                     max=root->val;
                 return root->val;
             }
             else
             {
                 if(r>max)
                     max=r;
                 return r+root->val;
             }
         }
         
         
     }
     int maxPathSum(TreeNode* root) {
         int max=INT_MIN;
         int temp=maxPathSumHelper(root,max);
         return temp>max?temp:max;
         
     }
 };