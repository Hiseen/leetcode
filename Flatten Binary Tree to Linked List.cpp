class Solution {
public:
    void flatten(TreeNode* root) {
        if(root)
        {
            vector<int> nums;
        In(root,nums);
        TreeNode *p=root;
        for(int i=1;i<nums.size();i++)
        {
            p->right=new TreeNode(nums[i]);
            p->left=NULL;
            p=p->right;
        }
        }
    }
    private:
    void In(TreeNode *node,vector<int> &nums)
    {
        nums.push_back(node->val);
         if(node->left)
        In(node->left,nums);
          if(node->right)
        In(node->right,nums);
        
    }
};