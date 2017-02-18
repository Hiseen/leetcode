class Solution {
 public:
     int findComplement(int num) {
         unsigned int m=0x40000000;
         while(!(m & num))m>>=1;
         return (m | m-1) ^ num;
     }
 };