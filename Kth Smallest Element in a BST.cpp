class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result=0,count=0;
        travel(root,result,count,k);
        return result;
        
    }
    bool travel(TreeNode* root,int& result,int &count,int max_count)
    {
        if(root->left)
            if(travel(root->left,result,count,max_count))
            return true;
        result=root->val;
        count+=1;
        if(count==max_count)
            return true;
        if(root->right)
            if(travel(root->right,result,count,max_count))
            return true;
        return false;
    }
};