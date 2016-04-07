class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
        return vector<int>();
        vector<int> nums;
        In(nums,root);
        return nums;
    }
    private:
    void In(vector<int> &nums,TreeNode *node)
    {
        if(node->left)
           In(nums,node->left);
           nums.push_back(node->val);
           if(node->right)
           In(nums,node->right);
           
    }
};