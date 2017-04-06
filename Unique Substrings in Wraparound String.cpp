class Solution {
 public:
     int findSubstringInWraproundString(string p) {
      int length[26]={0};
      int size=p.size(),lennow=1;
      if(size==0)return 0;
      if(size==1)return 1;
      length[p[0]-'a']=1;
      for(int i=1;i<size;++i)
      {
          if(p[i]-p[i-1]==1||(p[i]=='a' && p[i-1]=='z'))
             ++lennow;
          else
             lennow=1;
          for(int j=0;j<lennow;++j)
          {
              if(j+1>length[p[i-j]-'a'])
                 ++length[p[i-j]-'a'];
          }
      }
      int sum=0;
      for(int i=0;i<26;++i)
         sum+=length[i];
     return sum;
     }
 };