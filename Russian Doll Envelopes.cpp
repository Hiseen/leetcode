auto f=[](const pair<int,int>& p1,const pair<int,int>& p2)
 {
     if(p2.first>p1.first)
         return true;
     else if(p2.first==p1.first)
         return p2.second>=p1.second;
     else
         return false;
 };
     
 bool gt(const pair<int,int>& p1,const pair<int,int>& p2)
 {
     return p1.first>p2.first && p1.second>p2.second;    
 }
 class Solution {
 public:
     int maxEnvelopes(vector<pair<int, int>>& envelopes) {
         if(envelopes.empty())return 0;
         map<pair<int,int>,int,decltype(f)> m(f);
         sort(envelopes.begin(),envelopes.end(),[](const pair<int,int>& p1,const pair<int,int>& p2){return !f(p1,p2);});
         for(auto i:envelopes)
         {
             auto target=m.begin();
             int max=0;
             while(target!=m.end())
             {
                  if(gt(target->first,i) && target->second>max)
                         max=target->second;
                  ++target;
             }
                 m[i]=max+1;
         }
         int res=1;
         for(auto i:m)
         {
             if(i.second>res)res=i.second;
         }
         return res;
     }
 };