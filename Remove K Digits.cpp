class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k)return "0";
        int top=0;
        int count=0;
        int now=0;
        string res;
        while(count<k && top!=num.size())
        {
            bool finded=false;
            for(int i=top+1;i<num.size();++i)
            {
                if(num[i]<num[top])
                {
                    if(i-top<=k-count)
                    {
                        count+=i-top;
                        if(num[i]=='0' && top==0)
                            top=i+1;
                        else
                            top=i;
                        finded=true;
                        break;
                    }
                }
            }
            if(!finded)res+=num[top++];
        }
        if(count<k) res=res.substr(0,res.size()-k+count);
        else if(top!=num.size())res+=num.substr(top);
        int index=0;
        while(res[index++]=='0');
        res=res.substr(index-1);
        if(res.empty())return "0";
        else return res;
    }
};