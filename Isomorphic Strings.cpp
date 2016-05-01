class Solution {
 public:
     bool isIsomorphic(string s, string t) {
         int size=s.size();
         int hash_s[200],hash_t[200];
         for(int i=0;i<200;++i)
         {
             hash_s[i]=0;
             hash_t[i]=0;
         }
         for(int i=0;i<size;++i)
         {
             if(hash_s[s[i]])
             {
                 if(hash_s[s[i]]!=t[i])
                     return false;
             }
             else
             {
                 if(hash_t[t[i]])
                     return false;
                 hash_s[s[i]]=t[i];
                 hash_t[t[i]]=s[i];
             }
         }
         return true;
     }
 };