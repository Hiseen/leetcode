class Solution {
 public:
     bool isHappy(int n) {
         bool hash[1000];
         memset(hash,0,sizeof(hash));
         while(n!=1)
         {
             int temp=n;
             n=0;
             while(temp)
             {
                 n+=(temp%10)*(temp%10);
                 temp/=10;
             }
             if(hash[n])
                 return false;
             hash[n]=true;
         }
         return true;
     }
 };