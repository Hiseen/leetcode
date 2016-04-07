class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0,mid,end=nums.size()-1;
        if(!(end+1))return 0;
        while(1)
        {
            mid=(start+end)/2;
            if(nums[mid]==nums[end])
                return nums[mid];
            if(nums[mid]>nums[end])
                start=mid+1;
            else
                end=mid;
        }
    }
};