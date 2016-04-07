class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<vector<int>> result;
        if(!root)
            return result;
        stack.push_back(root);
        int size=0,temp_size=stack.size();
        bool reverse=false;
        while(size<stack.size())
        {
            vector<int> temp;
            while(size<temp_size)
            {
                temp.push_back(stack[size]->val);
                if(stack[size]->left)
                    stack.push_back(stack[size]->left);
                if(stack[size]->right)
                    stack.push_back(stack[size]->right);
                size++;
            }
            temp_size=stack.size();
            if(reverse)
                std::reverse(temp.begin(),temp.end());
            result.push_back(temp);
            reverse=!reverse;
        }
        return result;
    }
};