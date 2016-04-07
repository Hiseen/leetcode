class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        vector<TreeNode*> stack;
        int nowlen=0, nextlen;
        stack.push_back(root);
        nextlen=stack.size();
        while(nowlen<nextlen)
        {
            while(nowlen<nextlen)
            {
                if(stack[nowlen]->left)
                    stack.push_back(stack[nowlen]->left);
                if(stack[nowlen]->right)
                    stack.push_back(stack[nowlen]->right);
                nowlen++;
            }
            result.push_back(stack[nowlen-1]->val);
            nextlen=stack.size();
        }
        return result;
    }
};