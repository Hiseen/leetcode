class Solution {
 public:
 
     void dfs(int last,int index,const vector<int>& candidates,vector<vector<int>>& res,vector<int>& current)
     {
         for(int i=index;i<candidates.size();++i)
         {
             int temp=candidates[i];
             if(temp<last)
             {
                 current.push_back(temp);
                 dfs(last-temp,i,candidates,res,current);
                 current.pop_back();
             }
             else if(temp==last)
             {
                 current.push_back(temp);
                 res.push_back(current);
                 current.pop_back();
             }
             else break;
         }
     }
 
     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<int> current;
         vector<vector<int>> res;
         if(candidates.size()==0)return res;
         sort(candidates.begin(),candidates.end());
         dfs(target,0,candidates,res,current);
         return res;
     }
 };