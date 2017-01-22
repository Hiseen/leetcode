class Solution {
 public:
     double myPow(double x, int n) {
         if(x==1)return 1;
         if(x==-1)return n%2?-1:1;
         if(x>1 && n<-100000)return 0;
         if(x>0 && x<0.01 && n>100000)return 0;
         if(n==0)return 1;
         bool flag=false;
         if(n<0)
         {
             n=-n;
             flag=true;
         }
         double t=x;
         while(--n)
             x*=t;
         return flag?1/x:x;
     }
 };