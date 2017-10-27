class Solution {
public:
    
    bool helper(const string& s,int start,int end)
    {
        while(start<end)
        {
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    
    
    
    bool validPalindrome(string s) {
        int lo=0,hi=s.size()-1;
        if(helper(s,lo,hi))return true;
        while(lo<hi)
        {
            if(s[lo]!=s[hi])return helper(s,lo,hi-1) || helper(s,lo+1,hi);
            ++lo;
            --hi;
        }
        return true;
    }
};