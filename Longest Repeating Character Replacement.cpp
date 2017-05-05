class Solution {
 public:
     int characterReplacement(string s, int k) {
         int size=s.size();
         if(size==0)return 0;
         int res=1;
         if(k==0)
         {
             int temp=1;
             for(int i=1;i<size;++i)
             {
                 if(s[i]==s[i-1])
                     ++temp;
                 else
                 {
                     if(temp>res)res=temp;
                     temp=1;
                 }
             }
             return temp>res?temp:res;
         }
         for(int i='A';i<='Z';++i)
         {
             //cout<<(char)i<<endl;
             int lo=0,hi;
             int last=k;
             for(hi=0;hi<size;++hi)
             {
                 if(s[hi]!=i)
                 {
                     if(last)
                         --last;
                     else
                         break;
                 }
             }
             if(hi==size)return size;
             while(hi!=size)
             {
                 //cout<<lo<<" "<<hi<<endl;
                 if(hi-lo>res)res=hi-lo;
                 for(++lo;lo<size;++lo)
                     if(s[lo-1]!=i)
                     {
                         last++;
                         if(last==k || s[lo]==i)
                             break;
                     }
                 if(lo==size)break;
                 if(hi<lo)hi=--lo;
                 for(;hi<size;++hi)
                     if(s[hi]!=i)
                     {
                         if(last)
                             --last;
                         else
                             break;
                     }
             }
             
         }
         return res;
     }
 };