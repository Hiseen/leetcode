class Solution {
 public:
 
     void add(vector<int>& result,int now,int n)
     {
         if(now>n)return;
         else result.push_back(now);
         add(result,now*10,n);
         if(now%10!=9)
         add(result,now+1,n);
     }
 
     vector<int> lexicalOrder(int n) {
         vector<int> result;
         add(result,1,n);
         return result;
     }
 };