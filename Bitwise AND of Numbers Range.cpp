class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int temp1=m^n,temp2=m|n;
        if(temp1 && temp2)
        {
            if(temp1<m)
            {
                for(int i=31;i>=0;i--)
                if(temp1>>i&0x01)
                return (temp2>>(1+i))<<(1+i);
            }
            else
            return 0;
        }
        else
        return m;
    }
};