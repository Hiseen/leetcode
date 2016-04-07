class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool plus=false;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]==9)
               {
                   digits[i]=0;
                   plus=true;
               }
               else
               {
               digits[i]++;
               plus=false;
               break;
               }
        }
        if(plus)
        digits.insert(digits.begin(),1);
        return digits;
    }
};