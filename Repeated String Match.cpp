class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        bool flag=true;
        int lenb=B.size();
        int lena=A.size();
        for(int i=0;i<lena;++i)
        {
            if(A[i]==B[0])
            {
                int res=1;
                int j=i+1;
                int flag=true;
                for(int k=1;k<lenb;++k)
                {
                    if(j>=lena){j=0;++res;}
                    if(A[j++]!=B[k]){flag=false;break;}
                }
                if(flag)return res;
            }
        }
        return -1;
    }
};