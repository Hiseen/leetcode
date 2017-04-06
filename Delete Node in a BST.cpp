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
     TreeNode* deleteNode(TreeNode* root, int key) {
         if(!root)return nullptr;
         if(root->val>key)
             root->left=deleteNode(root->left,key);
         else if(root->val<key)
             root->right=deleteNode(root->right,key);
         else
         {
             if(!root->left && !root->right)
             {
                 delete root;
                 return nullptr;
             }
             else if(root->left && !root->left->right)
             {
                 root->val=root->left->val;
                 auto temp=root->left->left;
                 delete root->left;
                 root->left=temp;
             }
             else if(root->right && !root->right->left)
             {
                 root->val=root->right->val;
                 auto temp=root->right->right;
                 delete root->right;
                 root->right=temp;
             }
             else if(root->left)
             {
                 auto t=root->left;
                 while(t->right && t->right->right)
                     t=t->right;
                 root->val=t->right->val;
                 delete t->right;
                 t->right=t->right->left;
             }
             else if(root->right)
             {
                 auto t=root->right;
                 while(t->left && t->left->left)
                     t=t->left;
                 root->val=t->left->val;
                 delete t->left;
                 t->left=t->left->right;
             }
         }
         return root;
     }
 };