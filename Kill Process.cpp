class Solution {
 public:
     vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
         unordered_map<int,vector<int>> p;
         for(int i=0;i<pid.size();++i)
             p[ppid[i]].push_back(pid[i]);
         vector<int> res;
         res.push_back(kill);
         vector<int> temp;
         temp.push_back(kill);
         while(!temp.empty())
         {
             vector<int> new_temp;
             for(auto i:temp)
             {
                 for(auto j: p[i])
                 {
                     res.push_back(j);
                     new_temp.push_back(j);
                 }
             }
             temp.swap(new_temp);
         }
         return res;
     }
 };