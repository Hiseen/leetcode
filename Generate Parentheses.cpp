class Solution {
 public:
     void recurgen(set<string>& result,string now,int n,int stack)
     {
        if(n==0)
        {
            for(int i=0;i<stack;++i)now+=")";
            if(result.find(now)==result.end())
                 result.insert(now);
        }
        else
        {
            now+="(";
            for(int i=0;i<=stack+1;i++)
            {
                string temp=now;
                for(int j=0;j<i;j++)temp+=")";
                recurgen(result,temp,n-1,stack+1-i);
            }
        }
     }
 
 
     vector<string> generateParenthesis(int n) {
         set<string> result;
         vector<string> result2;
         string t;
         recurgen(result,t,n,0);
         std::copy(result.begin(), result.end(), std::back_inserter(result2));
         return result2;
     }
 };