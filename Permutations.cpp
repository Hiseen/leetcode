class Solution {
public:

    void recur(vector<int> nums, vector<int> now,vector<vector<int>> &result)
    {
        if(nums.size()==0)
        {
            result.push_back(now);
            return;
        }
        vector<int> pre(now);
        for(int i=0;i<nums.size();i++)
        {
            vector<int> temp(nums);
            temp.erase(temp.begin()+i);
            now.push_back(nums[i]);
            recur(temp,now,result);
            now=pre;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> now;
        recur(nums,now,result);
        return result;
        
    }
};