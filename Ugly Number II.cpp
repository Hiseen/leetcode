class Solution {
public:
    int min(int n1,int n2,int n3)
    {
        return n1<n2?(n1<n3?n1:n3):(n2<n3?n2:n3);
    }
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        int Ls[3],s[3];
        int dp[100000];
        dp[0]=1;
        for(int i=0;i<3;i++)
        {
            Ls[i]=1;
            s[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            int a=Ls[0]*2,b=Ls[1]*3,c=Ls[2]*5;
            int temp=min(a,b,c);
            dp[i]=temp;
            if(temp==a)
                {Ls[0]=dp[s[0]+1];s[0]+=1;}
            if(temp==b)
                {Ls[1]=dp[s[1]+1];s[1]+=1;}
            if(temp==c)
                {Ls[2]=dp[s[2]+1];s[2]+=1;}
        }
        return dp[n-1];
    }
};