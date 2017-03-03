class Solution {
 public:
     string addStrings(string num1, string num2) {
         int size1=num1.size();
         int size2=num2.size();
         
         if(size1>size2)
         {
             bool carry_in=false;
             for(int i=size2-1;i>=0;--i)
             {
                 int n1=num1[--size1]-'0';
                 int n2=num2[i]-'0';
                 int res=n1+n2+(int)carry_in;
                 if(res>=10)
                 {
                     carry_in=true;
                     res%=10;
                 }
                 else
                     carry_in=false;
                 num1[size1]=res+'0';
             }
             while(carry_in)
             {
                 carry_in=false;
                 if(size1!=0)
                 {
                     int t=num1[--size1]-'0';
                     if(t==9)
                     {
                         num1[size1]='0';
                         carry_in=true;
                     }
                     else
                         num1[size1]+=1;
                 }
                 else
                     num1.insert(0,1,'1');
             }
             return num1;
         }
         else
         {
             bool carry_in=false;
             for(int i=size1-1;i>=0;--i)
             {
                 int n1=num2[--size2]-'0';
                 int n2=num1[i]-'0';
                 int res=n1+n2+(int)carry_in;
                 if(res>=10)
                 {
                     carry_in=true;
                     res%=10;
                 }
                 else
                     carry_in=false;
                 num2[size2]=res+'0';
             }
             while(carry_in)
             {
                 carry_in=false;
                 if(size2!=0)
                 {
                     int t=num2[--size2]-'0';
                     if(t==9)
                     {
                         num2[size2]='0';
                         carry_in=true;
                     }
                     else
                         num2[size2]+=1;
                 }
                 else
                     num2.insert(0,1,'1');
             }
             return num2;
         }
         
         
         
     }
 };