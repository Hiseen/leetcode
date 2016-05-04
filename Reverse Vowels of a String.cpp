class Solution {
 public:
     string reverseVowels(string s) {
         int l=0,r=s.size()-1;
         char tr=s[r],tl=s[l];
         bool flag1=(tr=='o'||tr=='i'||tr=='a'||tr=='e'||tr=='u'||tr=='O'||tr=='I'||tr=='A'||tr=='E'||tr=='U');
         bool flag2=(tl=='o'||tl=='i'||tl=='a'||tl=='e'||tl=='u'||tl=='O'||tl=='I'||tl=='A'||tl=='E'||tl=='U');
         while(r>l)
         {
             if(flag1 && flag2)
             {
                 s[r]=tl;
                 s[l]=tr;
                 tr=s[--r];
                 tl=s[++l];
                 flag1=(tr=='o'||tr=='i'||tr=='a'||tr=='e'||tr=='u'||tr=='O'||tr=='I'||tr=='A'||tr=='E'||tr=='U');
                 flag2=(tl=='o'||tl=='i'||tl=='a'||tl=='e'||tl=='u'||tl=='O'||tl=='I'||tl=='A'||tl=='E'||tl=='U');
             }
             else
             {
                 if(!flag1)
                 {
                     tr=s[--r];
                     flag1=(tr=='o'||tr=='i'||tr=='a'||tr=='e'||tr=='u'||tr=='O'||tr=='I'||tr=='A'||tr=='E'||tr=='U');
                 }
                 if(!flag2)
                 {
                     tl=s[++l];
                     flag2=(tl=='o'||tl=='i'||tl=='a'||tl=='e'||tl=='u'||tl=='O'||tl=='I'||tl=='A'||tl=='E'||tl=='U');
                 }
             }
             
         }
         return s;
     }
 };