class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int index=0,max=nums.size()-1;
        while(index<=max)
        {
            stringstream ss;
            bool stop=(nums[index+1]-nums[index])!=1;
            int nowindex=index;
            ss<<nums[index];
            while(!stop && index<max)
            {
                index++;
                stop=(nums[index+1]-nums[index])!=1;
            }
            if(nowindex!=index)
            {
                ss<<"->";
                ss<<nums[index];
            }
            index++;
            result.push_back(ss.str());
        }
        return result;
    }
};