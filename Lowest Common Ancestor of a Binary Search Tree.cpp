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
     TreeNode* savesearch(vector<TreeNode*> &v,TreeNode* node,TreeNode *target)
     {
         if(node->left && savesearch(v,node->left,target)==target)
         {
                 v.push_back(node);
                 return target;
         }
         if(node->right && savesearch(v,node->right,target)==target)
         {
                 v.push_back(node);
                 return target;
         }
         if(node==target)
             v.push_back(node);
         return node;
     }
     bool search(TreeNode* node,TreeNode* target)
     {
         if(node==target)
             return true;
         if(node->left && search(node->left,target))
             return true;
         if(node->right && search(node->right,target))
             return true;
         return false;
     }
     
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         vector<TreeNode*> v;
         savesearch(v,root,p);
         int size=v.size();
         for(int i=0;i<size;++i)
             if(search(v[i],q))
                 return v[i];
         return nullptr;
         
     }
 };