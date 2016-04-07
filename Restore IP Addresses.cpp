class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res; 
            int num[4];
            In(res,num,0,s);
        return res;
    }
    private:
    void In(vector<string> &res,int *num,int index,string s)
    {
        if(index!=4)
        {
            int size=s.size();
            for(int i=0;i<(size>3?3:size);i++)
            {
                string cs=s;
                string sub=s.substr(0,i+1);
                if(sub[0]=='0' && sub.size()!=1)
                  goto finish;
                num[index]=atoi(sub.c_str());
                cs.erase(0,i+1);
                if(!(i==3 && num[index]>255))
                    In(res,num,index+1,cs);
            }
            finish:;
        }
        else
        {
            
            if(!s.size())
            {
                string newstr="";
                for(int i=0;i<4;i++)
            {
                if(num[i]>255)
                   {
                       goto end;//res.push_back("exceed");
                   }
                   else 
                   {
                   if(i!=3)
                   newstr+=itoa(num[i])+".";
                   else
                   newstr+=itoa(num[i]);
                   }
            }
            res.push_back(newstr);
            }
            end:;
        }
    }
    string itoa(int num)
    {
        string str="";
        if(num==0)
        str+='0';
        else
        while(num)
        {
            char a='0';
            a+=num%10;
            str.insert(0,(const char*)&a);
            num/=10;
        }
        return str;
    }
};