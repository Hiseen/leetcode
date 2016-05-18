class Solution {
 public:
     int countPrimes(int n) {
         vector<bool> hash(n,false);
         int count=0;
         int max=sqrt(n);
         for(int i=2;i<n;++i)
         {
             if(hash[i])continue;
             count++;
             if(i<=max)
             for(int j=i;j*i<n;++j)
                 hash[j*i]=true;
         }
         return count;
     }
 };