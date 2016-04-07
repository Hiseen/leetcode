class Solution {
public:
    int numDecodings(string s) {
        if(s=="" || s=="0" ||s[0]=='0')
            return 0;
        int dp[100000];
        dp[0]=(s[0]!=48?1:0);
        dp[1]=(s[1]!=48?1:0)*dp[0]+((s[0]==49 ||(s[0]==50 && s[1]<55))?1:0)*dp[0];
        for(int i=2;i<s.size();i++)
        {
            dp[i]=(s[i]!=48?1:0)*dp[i-1]+((s[i-1]==49 ||(s[i-1]==50 && s[i]<55))?1:0)*dp[i-2];
        }
        return dp[s.size()-1];
    }
};