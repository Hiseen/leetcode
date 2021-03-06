class Solution {
public:
    
    int findPaths(int m, int n, int N, int i, int j) {
        long rec[50][50][50];
        for(int k=0;k<50;++k)
        for(int l=0;l<50;++l)
        for(int z=0;z<50;++z)
            rec[k][l][z]=-1;
        return go(m,n,N,i,j,rec);
    }
    int go(int m,int n,int N,int i,int j,long rec[50][50][50])
    {
        if(N<=0 || i>=m || j>=n ||i<0 ||j<0)return 0;
        if(rec[N-1][i][j]!=-1)return rec[N-1][i][j];
        long res=0;
        if(i==0)
            ++res;
        if(i==m-1)
            ++res;
        if(j==0)
            ++res;
        if(j==n-1)
            ++res;
        res+=go(m,n,N-1,i+1,j,rec);
        res+=go(m,n,N-1,i-1,j,rec);
        res+=go(m,n,N-1,i,j-1,rec);
        res+=go(m,n,N-1,i,j+1,rec);
        res%=1000000007;
        rec[N-1][i][j]=res;
        return res;
    }
};