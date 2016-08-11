/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
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
         if(start==end)return NULL;
         int mid=start+(end-start)/2;
         TreeNode* root=new TreeNode(nums[mid]);
         if(end-start>1)
         {   
             root->left=buildBST(nums,start,mid);
             root->right=buildBST(nums,mid+1,end);
         }
         return root;
     }
 
 
     TreeNode* sortedListToBST(ListNode* head) {
         vector<int> nums;
         while(head)
         {
             nums.push_back(head->val);
             head=head->next;
         }
         return buildBST(nums,0,nums.size());
     }
 };