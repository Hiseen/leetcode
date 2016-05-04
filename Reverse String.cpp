class Solution {
 public:
     string reverseString(string s) {
         string result;
         int size=s.size()-1;
         for(int i=size;i>=0;--i)
             result+=s[i];
         return result;
     }
 };