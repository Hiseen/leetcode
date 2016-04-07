class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[100000],max=coins.size();
        dp[0]=0;
        for (int i=1;i<=amount;i++)
            dp[i]=-1;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<max;j++)
            {
                int a=coins[j];
                if(i==a)
                    {dp[i]=1;break;}
                if(i-a>0 && dp[i-a]!=-1)
                    dp[i]=dp[i]==-1?dp[i-a]+1:(1+dp[i-a])>dp[i]?dp[i]:1+dp[i-a];
            }
        }
        return dp[amount];
    }
};