class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int original_r=nums.size();
        int original_c=nums[0].size();
        if(original_r*original_c!=r*c)
            return nums;
        else
        {
            vector<vector<int>> res;
            vector<int> temp;
            for(int i=0;i<original_r;++i)
            for(int j=0;j<original_c;++j)
                temp.push_back(nums[i][j]);
            int now=0;
            for(int i=0;i<r;++i)
            {
                vector<int> t;
                for(int j=0;j<c;++j)
                {
                    t.push_back(temp[now++]);
                }   
                res.push_back(t);
            }
            return res;
        }
    }
};