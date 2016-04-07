class Solution {
public:
    int lengthOfLastWord(string s) {
        int IsOk=0;
        bool a=false;
        for(int i=s.size()-1;i>=0;i--)
           {
               if(!a)
                 { if(s[i]!=' ')
                     {IsOk=i;
                     a=true;
                     }
                 }
               else
               if(s[i]==' ')
                  return IsOk-i;
           }
           if(a)
           return (IsOk?IsOk+1:1);
           else
           return 0;
    }
};