class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max=0,size=nums.size();
        for(int i=0;i<size;++i)
        {
            if(max<i)return false;
            if(max>=size-1)return true;
            if(i+nums[i]>max)max=i+nums[i];
        }
    }
};