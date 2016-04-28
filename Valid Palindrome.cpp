class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        int size1=s.size();
        for(int i=0;i<size1;++i)
        {
            char a=s[i];
            if(a>=65 && a<=90)
                temp+=a;
            else if (a>=97 && a<=122)
                temp+=a-32;
            else if(a>=48 && a<=57)
                temp+=a;
        }
        int size2=temp.size()/2,size3=temp.size()-1;
        for(int i=0;i<size2;++i)
        {
            if(temp[i]!=temp[size3-i])
                return false;
        }
        return true;
        
    }
};