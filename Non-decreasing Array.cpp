class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag=false;
        int size=nums.size();
        for(int i=1;i<size;++i)
        {
            if(nums[i-1]>nums[i])
            {
                if(i>1 && i!=size-1 && nums[i-2]>nums[i] && nums[i-1]>nums[i+1])return false;
                if(!flag)flag=true;
                else return false;
            }
        }
        return true;
    }
};