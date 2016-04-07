class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int dp[100000];
        dp[0]=0;
        int max=0;
        for(int i=1;i<prices.size();i++)
        {
            int d=prices[i]-prices[i-1];
            dp[i]=(dp[i-1]+d)<0?0:(dp[i-1]+d);
            if(dp[i]>max)max=dp[i];
        }
        return max;
    }
};
