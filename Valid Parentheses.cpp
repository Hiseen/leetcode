class Solution {
public:
    bool isValid(string s) {
        string pre="({[";
        string aft=")}]";
        if(s.size()%2)
            return false;
        string stack="";
        for(int i=0;i<s.size();i++)
        {
            if(pre.find(s[i])!=pre.npos)
            {
                stack+=s[i];
            }
            else if(aft.find(s[i])!=aft.npos)
            {
                int index=pre.find(stack[stack.size()-1]);
                if(index==aft.find(s[i]))
                {
                    stack.erase(stack.size()-1,1);
                }
                else
                    return false;
            }
        }
        if(!stack.size())
            return true;
        else return false;
    }
};