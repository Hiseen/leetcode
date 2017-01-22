class Solution {
 public:
     vector<string> fizzBuzz(int n) {
         vector<string> result;
         for(int i=1;i<=n;++i)
         {
             if(!(i%3))
             {
                 if(!(i%5))
                     result.push_back("FizzBuzz");
                 else
                     result.push_back("Fizz");
             }
             else if(!(i%5))
                 result.push_back("Buzz");
             else
             {
                 string s;
                 int t=i;
                 while(t)
                 {
                     s = (char)(t % 10 + 48) + s;
                     t/=10;
                 }
                 result.push_back(s);
             }
         }
         return result;
     }
 };