class Solution {
 public:
     bool detectCapitalUse(string word) {
         if(word.size()<=1)return true;
         bool flag=word[0]<97;
         int size=word.size();
         bool flag2=word[1]<97;
         if(flag && flag2)
         {
             for(int i=2;i<size;++i)
                 if(word[i]>=97)
                     return false;
         }
         else if(flag)
         {
             for(int i=2;i<size;++i)
                 if(word[i]<97)
                     return false;
         }
         else if(!flag && !flag2)
         {
             for(int i=2;i<size;++i)
                 if(word[i]<97)
                     return false;
         }
         else 
             return false;
         return true;
                     
     }
 };