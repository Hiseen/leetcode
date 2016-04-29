class NumArray {
 public:
     NumArray(vector<int> &nums) {
         if(nums.size()>0)
         {
             dp[0]=nums[0];
             for(int i=1;i<nums.size();i++)
                 dp[i]=dp[i-1]+nums[i];
         }
     }
 
     int sumRange(int i, int j) {
         return i==0?dp[j]:dp[j]-dp[i-1];
     }
 private:
     int dp[100000];
 };
 
 
 // Your NumArray object will be instantiated and called as such:
 // NumArray numArray(nums);
 // numArray.sumRange(0, 1);
 // numArray.sumRange(1, 2);