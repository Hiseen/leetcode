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
 
     int robhelper(TreeNode* t,bool robbed,unordered_map<TreeNode*,int>& map1,unordered_map<TreeNode*,int>& map2)
     {
         if(!t)return 0;
         int result_rob=0,result_norob=0;
         if(!robbed)
         {
             if(map1.find(t)!=map1.end())result_rob=map1[t];
             else
             {
                 result_rob+=t->val;
                 if(t->left)
                     result_rob+=robhelper(t->left,true,map1,map2);
                 if(t->right)
                     result_rob+=robhelper(t->right,true,map1,map2);
                 map1[t]=result_rob;
             }
         }
         if(map2.find(t)!=map2.end())result_norob=map2[t];
         else
         {
             if(t->left)
                 result_norob+=robhelper(t->left,false,map1,map2);
             if(t->right)
                 result_norob+=robhelper(t->right,false,map1,map2);
             map2[t]=result_norob;
         }
         return result_rob>result_norob?result_rob:result_norob;
     }
 
 
 
 
     int rob(TreeNode* root) {
         unordered_map<TreeNode*,int> map1;
         unordered_map<TreeNode*,int> map2;
         return robhelper(root,false,map1,map2);
     }
 };