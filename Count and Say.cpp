class Solution {
 public:
     string countAndSay(int n) {
         string result("1");
         for(int i=1;i<n;i++)
         {
             string temp;
             int count=0,c=-1,size=result.size();
             for(int j=0;j<size;++j)
             {
                 if(c==-1)
                 {
                     c=result[j];
                     count++;
                 }
                 else
                 {
                     if(result[j]!=c)
                     {
                         temp+=char(48+count);
                         temp+=char(c);
                         count=1;
                         c=result[j];
                     }
                     else
                         count++;
                 }
             }
             temp+=char(48+count);
             temp+=char(c);
             result=temp;
         }
         return result;
     }
 };