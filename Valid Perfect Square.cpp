class Solution {
 public:
     bool isPerfectSquare(int num) {
         if(num>2147395600)return false;
         int r=46340;
         int l=1;
         int tr,tl;
         while(l<r)
         {
             tr=r;
             tl=l;
             int mid=(l+r)/2;
             if(mid*mid>num)
                 r=mid;
             else if(mid*mid<num)
                 l=mid+1;
             else
                 return true;
         }
         for(int i=tl;i<tr+1;i++)
             if(i*i==num)
             return true;
         return false;
     }
 };