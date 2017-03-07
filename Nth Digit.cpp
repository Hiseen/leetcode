class Solution {
 public:
     int findNthDigit(int n) {
         if(n<10)return n;
         if(n==10)return 1;
         long long num1=9;
         int num2=1;
         while(num1*num2<n)
         {
             n-=num1*num2;
             num1*=10;
             ++num2;
         }
         num1/=10;
         long long num3=1;
         for(int i=0;i<num2-1;++i)
             num3*=10;
         --n;
         long long target=num3+n/num2;
         for(int i=0;i<num2-n%num2-1;++i)
             target/=10;
         return target%10;
         
     }
 };