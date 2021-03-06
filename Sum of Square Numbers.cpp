class Solution {
public:
    bool judgeSquareSum(int c) {
        int lo=0,hi=sqrt(c);
        while(lo<=hi)
        {
            int s=lo*lo+hi*hi;
            if(s>c)
                --hi;
            else if(s<c)
                ++lo;
            else
                return true;
        }
        return false;
    }
};