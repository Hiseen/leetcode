class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root)
        {int depth=1;
        Search(depth,1,root);
        return depth;
        }
        else
        return 0;
    }
void Search(int &result,int depth,TreeNode *node)
{
    if(node->left)
        Search(result,depth+1,node->left);
    if(node->right)
        Search(result,depth+1,node->right);
    if(!node->left && !node->right)
        result=result<depth?depth:result;
}
    
};