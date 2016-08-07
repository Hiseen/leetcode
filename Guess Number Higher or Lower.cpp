// Forward declaration of guess API.
 // @param num, your guess
 // @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
 int guess(int num);
 
 class Solution {
 public:
     int guessNumber(int n) {
         if(n==1)
             return 1;
         if(n==2147483647)
             if(!guess(2147483647))return 2147483647;
         int left=1,right=n;
         while(1)
         {
             int mid=n<1073741823?(left+right)/2:left/2+right/2;
             int res=guess(mid);
             if(!res)
                 return mid;
             else if(res==-1)
                 right=mid-1;
             else 
                 left=mid+1;
         }
     }
 };