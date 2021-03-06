class Solution {
public:
    int maximumSwap(int num) {
        int parts[10];
        int sz=0;
        int result=num;
        while(num)
        {
            parts[sz++]=num%10;
            num/=10;
        }
        if(sz<2)return result;
        for(int i=sz-1;i>=0;--i)
        {
            int max=i;
            for(int j=i-1;j>=0;--j)
            {
                if(parts[j]>=parts[max])
                {
                    max=j;
                }
            }
            if(parts[i]!=parts[max])
            {
                int t=parts[i];
                parts[i]=parts[max];
                parts[max]=t;
                result=0;
                for(int k=sz-1;k>=0;--k)
                {
                    result*=10;
                    result+=parts[k];
                }
                return result;
            }
        }
        return result;
    }
};