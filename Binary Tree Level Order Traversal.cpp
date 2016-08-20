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
     vector<vector<int>> levelOrder(TreeNode* root) {
         vector<TreeNode*> stack;
         vector<vector<int>> result;
         if(root)stack.push_back(root);
         while(!stack.empty())
         {
             int start=0,end=stack.size();
             vector<int> temp;
             vector<TreeNode*> newstack;
             while(start<end)
             {
                 temp.push_back(stack[start]->val);
                 if(stack[start]->left)
                     newstack.push_back(stack[start]->left);
                 if(stack[start]->right)
                     newstack.push_back(stack[start]->right);
                 start++;
             }
             result.push_back(temp);
             stack.swap(newstack);
         }
         return result;
     }
 };