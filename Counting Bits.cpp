class Solution {
 public:
     vector<int> countBits(int num) {
         if(num>=2)
         {
             vector<int> res;
             res.push_back(0);
             res.push_back(1);
             int now=2,range=2;
             while(1)
             {
                 for(int i=0;i<range;++i)
                 {
                     res.push_back(1+res[i]);
                     now++;
                     if(now-1==num)
                         return res;
                 }
                 range*=2;
             }
         }
         else if(num==1)
             return {0,1};
         else
             return {0};
         
     }
 };