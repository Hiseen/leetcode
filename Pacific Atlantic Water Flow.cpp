class Solution {
public:
    void Check(vector<vector<int>>& matrix,int i,int j,bool& atlantic,bool& pacific,int maxi,int maxj)
    {
        if(atlantic && pacific)return;
        if(matrix[i][j]==-1)return;
        int t=matrix[i][j];
        matrix[i][j]=-1;
        if(i+1>=maxi)
            atlantic=true;
        else if(t>=matrix[i+1][j])
            Check(matrix,i+1,j,atlantic,pacific,maxi,maxj);
        if(i-1<0)
            pacific=true;
        else if(t>=matrix[i-1][j])
            Check(matrix,i-1,j,atlantic,pacific,maxi,maxj);
        if(j+1>=maxj)
            atlantic=true;
        else if(t>=matrix[i][j+1])
            Check(matrix,i,j+1,atlantic,pacific,maxi,maxj);
        if(j-1<0)
            pacific=true;
        else if(t>=matrix[i][j-1])
            Check(matrix,i,j-1,atlantic,pacific,maxi,maxj);
        matrix[i][j]=t;
    }
    
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> result;
        int maxi=matrix.size();
        if(maxi==0)return result;
        int maxj=matrix[0].size();
        for(int i=0;i<maxi;++i)
        for(int j=0;j<maxj;++j)
        {
            bool a=false,p=false;
            Check(matrix,i,j,a,p,maxi,maxj);
            if(a && p)
                result.push_back({i,j});
        }
        return result;
    }
};