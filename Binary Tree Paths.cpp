class Solution {
public:
    void DFS(vector<string> &v, TreeNode* node,string str)
    {
        char buffer[200];
        sprintf(buffer,"%d",node->val);
        str.append(buffer);
        if(node->left)
            DFS(v,node->left,str+"->");
        if(node->right)
            DFS(v,node->right,str+"->");
        if(!node->left && !node->right)
            v.push_back(str);
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        if(!root)
            return res;
        DFS(res,root,"");
        return res;
    }
};