class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
        {
            return vector<int>();
        }
        else
        {vector<int> set;
        A(set,root);
        return set;
        }
    }
    
private:
   void A(vector<int> &set,TreeNode *Node)
   {
       set.push_back(Node->val);
       if(Node->left)
          A(set,Node->left);
          if(Node->right)
          A(set,Node->right);
   }
};