class Solution {
 public:
 
     void helper(int k,int n,int vaild_use,int now,unordered_set<int>& res)
     {
         if(n>9*k || n<1)return;
         if(k==1)
         {
             if(vaild_use & (1<<n))
                 res.insert(now|(1<<n));
         }
         else
         {
             for(int i=0;i<9;++i)
             {
                 if(vaild_use & (1<<i))
                     helper(k-1,n-i-1,vaild_use-(1<<i),now|(1<<i),res);
             }
         }
     }
 
 
 
 
 
     vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>> res;
         if(k==0)return res;
         unordered_set<int> temp;
         helper(k,n-1,511,0,temp);
         for(auto i:temp)
         {
             vector<int> t;
             for(int j=0;j<9;++j)
             {
                 if(i & (1<<j))
                     t.push_back(j+1);
             }
             res.push_back(t);
         }
         return res;
     }
 };