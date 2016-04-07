class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n>0)
        {
            int temp=n%26;
            if(!temp)temp=26;
            result=char(temp+64)+result;
            n=(n-temp)/26;
        }
        return result;
    }
};