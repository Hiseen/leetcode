class Solution {
 public:
     bool repeatedSubstringPattern(string s) {
         int size=s.size();
         int max=size/2;
         char temp[max+2];
         temp[0]=s[0];
         int len=0;
         bool d=size%2!=0;
         for(int i=1;i<=max;++i)
         {
             ++len;
             if(!(size%len))
             {
                 bool flag=true;
                 for(int j=i;j<size;j+=len)
                 {
                     for(int k=0;k<len;++k)
                         if(s[j+k]!=temp[k])
                         {
                             flag=false;
                             break;
                         }
                     if(!flag)break;
                 }
                 if(flag)
                     return true;
             }
             temp[i]=s[i];
             if(d){++len;temp[++i]=s[i];}
         }
         return false;
     }
 };