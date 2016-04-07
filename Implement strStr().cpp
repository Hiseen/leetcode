class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack==needle)
            return 0;
        if(needle=="")
            return 0;
        int nowindex=0,resultindex=0,max1=haystack.size(),max2=needle.size()-1;
        if(max2+1>max1)
            return -1;
        for(int i=0;i<max1;i++)
        {
            if(haystack[i]==needle[nowindex])
            {
                if(nowindex==0)
                    resultindex=i;
                if(nowindex==max2)
                    return resultindex;
                nowindex++;
            }
            else
            {
                i-=nowindex;
                nowindex=0;
            }
        }
        return -1;
    }
};