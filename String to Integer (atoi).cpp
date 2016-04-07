class Solution {
public:
    int myAtoi(string str) {
        int index=0;
        while(str[index]==' ')
            index++;
        if(index==str.size())
            return 0;
        unsigned long long result=0;
        bool negative=false;
        if(str[index]==45)
        {
            negative=true;
            index++;
        }
        else if(str[index]==43)
            index++;
        while(1)
            {
                char temp=str[index];
                if(temp>=48 && temp<=57)
                {
                    result*=10;
                    result+=temp-48;
                    index++;
                    if(result>2147483647)
                        if(negative)return -2147483648;
                        else return 2147483647;
                }
                else
                {
                    if(result>2147483647)
                        if(negative)return -2147483648;
                        else return 2147483647;
                    return negative?-result:result;
                }
                
            }
    }
};