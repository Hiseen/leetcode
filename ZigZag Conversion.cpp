class Solution {
public:
    string convert(string s, int numRows) {
        if(s=="" || numRows==1 || s.size()<=numRows)
            return s;
        string result=string();
        int a=0,b=numRows,c=0;
        for(int i=b;i>0;i--)
        {
            int d=2*(i-1);
            result+=s[a];
            a+=d;
            while(a<s.size())
            {
                if(d)
                    result+=s[a];
                if(c)
                {
                    a+=c;
                    if(a<s.size())
                        result+=s[a];
                }
                a+=d;
            }
            a=b-i+1;
            c+=2;
        }
        return result;
    }
};