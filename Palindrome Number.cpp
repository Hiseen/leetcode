class Solution {
 public:
     bool isPalindrome(int x) {
         if(x<0)
             return false;
         else
         {
             int last_n=0;
             while(x)
             {
                 int n = pow(10, (int)log10(x));
                 if (last_n && last_n!= n*100)
 				{
 				    int temp=(last_n/n)/100;
 				    if(x%temp)
 				        return false;
 				    x/=temp;
 				    n = pow(10, (int)log10(x));
 				}
 			    if (x!=0 && x<10)
 				    return true;
 			    if (x==0)
 				    return false;
                 if(int(x/n)==x%10)
                 {
                     x-=int(x/n)*n;
                     x-=x%10;
                     x/=10;
                     last_n=n;
                 }
                 else
                     return false;
             }
             return true;
         }
     }
 };