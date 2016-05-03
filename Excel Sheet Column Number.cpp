class Solution {
 public:
     int titleToNumber(string s) {
         int res=0,size=s.size(),p=1;
         for(int i=size-1;i>=0;--i)
         {
             int temp=s[i];
             if(temp<91)
                 temp-=64;
             else
                 temp-=96;
             res+=p*temp;
             p*=26;
         }
         return res;
     }
 };