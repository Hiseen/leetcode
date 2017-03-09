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
     int recur(TreeNode* root,unordered_map<int,int>& m,int& max)
     {
         int s=root->val;
         if(root->left)
             s+=recur(root->left,m,max);
         if(root->right)
             s+=recur(root->right,m,max);
         m[s]+=1;
         if(m[s]>max)
             max=m[s];
         return s;
     }
 
 
     vector<int> findFrequentTreeSum(TreeNode* root) {
         unordered_map<int,int> m;
         int max=INT_MIN;
         vector<int> res;
         if(root)recur(root,m,max);
         for(auto i:m)
             if(i.second==max)
                 res.push_back(i.first);
         return res;
         
     }
 };