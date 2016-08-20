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
     TreeNode* buildBST(vector<int>& nums,int start,int end)
     {
         if(start==end)
             return NULL;
         else
         {
             int mid=start+(end-start)/2;
             TreeNode* newnode=new TreeNode(nums[mid]);
             newnode->left=buildBST(nums,start,mid);
             newnode->right=buildBST(nums,mid+1,end);
             return newnode;
         }
     }
 
     TreeNode* sortedArrayToBST(vector<int>& nums) {
         return buildBST(nums,0,nums.size());
     }
 };