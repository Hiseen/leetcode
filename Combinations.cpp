class Solution {
 public:
 
     void recur(int n,int k,int now,int index,vector<int> v,vector<vector<int>>& res)
     {
         if(v.size()==k)
         {
             res.push_back(v);
             return;
         }
         for(int i=now+1;i<=n-(k-index);i++)
         {
             v.push_back(i);
             recur(n,k,i,index+1,v,res);
             v.pop_back();
         }
     }
 
 
     vector<vector<int>> combine(int n, int k) {
         vector<vector<int>> res;
         recur(n,k,0,1,vector<int>{},res);
         return res;
     }
 };