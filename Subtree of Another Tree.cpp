/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSame(TreeNode* s,TreeNode*t)
    {
        if(!s)return t==nullptr;
        return t!=nullptr && s->val==t->val && isSame(s->left,t->left) && isSame(s->right,t->right);
    }
    bool recur(TreeNode*s,TreeNode* t,bool& res)
    {
        if(res)return true;
        if(!s)return t==nullptr;
        if(isSame(s,t) || recur(s->left,t,res) || recur(s->right,t,res))
        {
            res=true;
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool f=false;
        recur(s,t,f);
        return f;
    }
};