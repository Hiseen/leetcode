class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxs[100000];
        int mins[100000];
        maxs[0]=nums[0];
        mins[0]=nums[0];
        int temp=nums[0]; 
        for(int i=1;i<nums.size();i++)
        {
            int c=nums[i];
            int a=maxs[i-1]*c,b=mins[i-1]*c;
            maxs[i]=a>b?a>c?a:b>c?b:c:b>c?b:c;
            mins[i]=a<b?a<c?a:b<c?b:c:b<c?b:c;
            if(maxs[i]>temp)
                temp=maxs[i];
                
        }
        return temp;
    }
};