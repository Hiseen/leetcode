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
 
     void AddNodes(TreeNode* root,vector<TreeNode*>& v)
     {
         if(root->left)
             AddNodes(root->left,v);
         v.push_back(root);
         if(root->right)
             AddNodes(root->right,v);
     }
     void Helper(TreeNode* root,int num,int sum,int& count)
     {
         if(num+root->val==sum)
             ++count;
         if(root->left)
             Helper(root->left,num+root->val,sum,count);
         if(root->right)
             Helper(root->right,num+root->val,sum,count);
     }
 
 
     int pathSum(TreeNode* root, int sum) {
         if(!root)return 0;
         int res=0;
         vector<TreeNode*> v;
         AddNodes(root,v);
         for(auto i:v)
             Helper(i,0,sum,res);
         return res;
         
     }
 };