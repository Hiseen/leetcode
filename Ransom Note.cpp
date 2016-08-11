class Solution {
 public:
     bool canConstruct(string ransomNote, string magazine) {
         int size1=ransomNote.size(),size2=magazine.size();
         for(int i=0;i<size1;++i)
         {
             bool flag=false;
             for(int j=0;j<size2;++j)
                 if(magazine[j]==ransomNote[i])
                 {
                     magazine.erase(magazine.begin()+j);
                     --size2;
                     flag=true;
                     break;
                 }
             if(!flag)
                 return false;
         }
         return true;
     }
 };