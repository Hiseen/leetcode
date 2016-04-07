class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int len=matrix.size();
        if(!len)return result;
        int max=matrix[0].size();
        for(int i=0;i<max;i++)
            result.push_back(matrix[0][i]);
        int nowi=0,nowj=max-1,delta=1;
        max-=1;
        len-=1;
        if(!len || !max)
        {
            for(int i=1;i<len+1;++i)
            for(int j=0;j<max+1;++j)
                result.push_back(matrix[i][j]);
            return result;
        }
        if(len>max)
        {
            while(max && len)
            {
                for(int k=0;k<len;++k)
                {
                    nowi+=delta;
                    result.push_back(matrix[nowi][nowj]);
                }
                for(int k=0;k<max;++k)
                {
                    nowj-=delta;
                    result.push_back(matrix[nowi][nowj]);
                }
                delta=-delta;
                if(max>0)
                    max-=1;
                if(len>0)
                    len-=1;
            }
            for(int k=0;k<len;++k)
            {
                nowi+=delta;
                result.push_back(matrix[nowi][nowj]);
            }
        }
        else
        {
            while(max && len)
            {
                for(int k=0;k<len;++k)
                {
                    nowi+=delta;
                    result.push_back(matrix[nowi][nowj]);
                }
                for(int k=0;k<max;++k)
                {
                    nowj-=delta;
                    result.push_back(matrix[nowi][nowj]);
                }
                delta=-delta;
                if(max>0)
                    max-=1;
                if(len>0)
                    len-=1;
            }
        }
        return result;
    }
};