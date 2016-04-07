class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root)
        {
            vector<TreeNode*> stack;
            In(stack,root);
            vector<int> result;
            for(int i=stack.size()-1;i>=0;i--)
               result.push_back(stack[i]->val);
            return result;
        }
        else
            return vector<int>();
        
    }
    
private:
void In(vector<TreeNode*> &stack,TreeNode* node)
{
    stack.push_back(node);
    if(node->right)
        In(stack,node->right);
        if(node->left)
        In(stack,node->left);
}
    
};