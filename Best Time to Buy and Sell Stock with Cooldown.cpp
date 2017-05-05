class Solution {
 public:
     int maxProfit(vector<int>& prices) {
         if(prices.empty())return 0;
         int mp[100000]={0};
         if(prices[1]>prices[0])
         {
             mp[1]=prices[1]-prices[0];
         }
         int size=prices.size();
         for(int i=2;i<size;++i)
         {
             for(int j=i-1;j>=0;--j)
             {
                 if(j<2)
                 {
                     if(prices[i]-prices[j]>mp[i])
                     {
                         mp[i]=prices[i]-prices[j];
                     }
                 }
                 else if(mp[j-2]-prices[j]+prices[i]>mp[i])
                 {
                     mp[i]=mp[j-2]-prices[j]+prices[i];
                 }
             }
             if(mp[i-1]>mp[i])mp[i]=mp[i-1];
         }
         return mp[size-1];
     }
 };