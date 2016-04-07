class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root)
        {vector<vector<int>> nums;
        vector<TreeNode*> stack;
        stack.push_back(root);
         int cur = 0;  
         int last = 1;  
        while(stack.size()>cur)
        {
            last=stack.size();
            vector<int> smallset;
           while(last>cur)
            {
                smallset.push_back(stack[cur]->val);
                if(stack[cur]->left)
                   stack.push_back(stack[cur]->left);
                if(stack[cur]->right)
                   stack.push_back(stack[cur]->right);
                   cur++;
            }
            nums.push_back(smallset);
        }
        reverse(nums.begin(),nums.end());
        return nums;
        }
        else
        return vector<vector<int>>();
    }
    
private:


};