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
     void recur(TreeNode* root,vector<int> path,vector<vector<int>>& result,int now,int target)
     {
         int temp=now+root->val;
         path.push_back(root->val);
         if(temp==target && !root->left && !root->right)
             result.push_back(path);
         else
         {
             if(root->left)
                 recur(root->left,path,result,temp,target);
             if(root->right)
                 recur(root->right,path,result,temp,target);
         }
     }
 
 
 
     vector<vector<int>> pathSum(TreeNode* root, int sum) {
         vector<vector<int>> result;
         vector<int> temp;
         if(root)
             recur(root,temp,result,0,sum);
         return result;
     }
 };