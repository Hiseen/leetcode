class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
        return 0;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        int now=0;
        int depth=0;
        while(nodes.size())
        {
            int last=nodes.size();
            depth++;
            while(now<last)
            {
                if(nodes[now]->left)
               nodes.push_back(nodes[now]->left);
            if(nodes[now]->right)
               nodes.push_back(nodes[now]->right);
            if(!nodes[now]->left && !nodes[now]->right)
               return depth;
               ++now;
            }
               
        }
    }
    private:
    
};