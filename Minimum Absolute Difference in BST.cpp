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
 
     void InOrder(TreeNode* n,vector<int>& v)
     {
         if(n->left)
             InOrder(n->left,v);
         v.push_back(n->val);
         if(n->right)
             InOrder(n->right,v);
     }
 
 
 
     int getMinimumDifference(TreeNode* root) {
         vector<int> v;
         InOrder(root,v);
         int size=v.size();
         int min=INT_MAX;
         for(int i=0;i<size-1;++i)
         {
             int t=v[i+1]-v[i];
             if(t<min)min=t;
         }
         return min;
     }
 };