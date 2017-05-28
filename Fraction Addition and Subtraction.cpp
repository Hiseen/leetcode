class Solution {
 public:
     int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 
     string fractionAddition(string expression) {
         bool isneg=false;
         int num=0;
         int de=0;
         int i=0;
         while(i<expression.size())
         {
             bool isneg2=false;
             int num2=0;
             int de2=0;
             if(expression[i]=='-'){++i;isneg2=true;}
             else if(expression[i]=='+')++i;
             while(expression[i]!='/')
             {
                 num2*=10;
                 num2+=expression[i++]-'0';
             }
             i++;
             while(i<expression.size() && expression[i]!='+' && expression[i]!='-')
             {
                 de2*=10;
                 de2+=expression[i++]-'0';
             }
             if(de==0)
             {
                 isneg=isneg2;
                 num=num2;
                 de=de2;
             }
             else
             {
                 if(isneg==isneg2)
                 {
                     num*=de2;
                     num2*=de;
                     num+=num2;
                     de*=de2;
                     int g=gcd(num,de);
                     num/=g;
                     de/=g;
                 }
                 else
                 {
                     num*=de2;
                     num2*=de;
                     num-=num2;
                     de*=de2;
                     int g=gcd(num,de);
                     num/=g;
                     de/=g;
                     if(num<0)
                     {
                         num*=-1;
                         isneg=!isneg;
                     }
                 }
             }
         }
         if(de<0)
         {
             isneg=!isneg;
             de*=-1;
         }
         ostringstream out;
         out<<(isneg?num*(-1):num)<<"/"<<de;
         return out.str();
     }
 };