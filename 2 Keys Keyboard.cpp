class Solution {
public:
    int minSteps(int n) {
        int dp[1001];
        for(int i=0;i<1001;++i)dp[i]=INT_MAX;
        dp[1]=0;
        for(int i=2;i<n+1;++i)
        {
            int m=sqrt(i);
            while(m>0)
            {
                if(i%m==0)
                {
                    if(m==1) dp[i]=min(dp[i],i);
                    else dp[i]=min(dp[i],min(dp[i/m]+m,dp[m]+i/m));
                }
                --m;
            }
        }
        return dp[n];
        
    }
    
};