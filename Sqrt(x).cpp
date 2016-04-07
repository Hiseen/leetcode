class Solution {
public:
    int mySqrt(int x) {
        int start=0,mid,end=x;
        if(x==0)return 0;
        if(x==1)return 1;
        while(1)
        {
            mid=(start+end)/2;
            if(mid==end)
                return mid;
            if((x/mid)<mid)
                end=mid-1;
            else if((x/(mid+1))>mid)
                start=mid+1;
            else return mid;
        }
    }
};