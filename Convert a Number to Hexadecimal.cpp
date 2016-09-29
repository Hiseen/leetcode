class Solution {
 public:
     string toHex(int num) {
         if(num==0)return "0";
         string str;
         bool started=false;
         for(int i=0;i<8;++i)
         {
             int sum=((unsigned int)num<<(4*i))>>28;
             if(sum!=0)
                 started=true;
             if(started)
             {
                 if(sum>=10)
                     str+=87+sum;
                 else
                     str+='0'+sum;
             }
         }
         return str;
     }
 };