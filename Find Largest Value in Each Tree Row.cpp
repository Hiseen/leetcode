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
     void recur(TreeNode* root,vector<int>& result,int depth,int& size)
     {
         if(depth>size)
         {
             ++size;
             result.push_back(root->val);
         }
         else
         {
             if(result[depth]<root->val)
                 result[depth]=root->val;
         }
         if(root->left)
             recur(root->left,result,depth+1,size);
         if(root->right)
             recur(root->right,result,depth+1,size);
     }
 
 
 
     vector<int> largestValues(TreeNode* root) {
         vector<int> res;
         int size=-1;
         if(root)recur(root,res,0,size);
         return res;
     }
 };