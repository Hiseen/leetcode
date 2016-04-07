class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
        return nullptr;
        In(root);
        return root;
        
        
        
        
        
    }
    private:
    void In(TreeNode *node)
    {
        if(node->left)
           In(node->left);
        if(node->right)
           In(node->right);
           TreeNode *temp=node->left;
        node->left=node->right;   
        node->right=temp;
    }
};