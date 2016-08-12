class Solution {
 public:
     int maxArea(vector<int>& height) {
         int l=0,r=height.size()-1;
         int max=0;
         while(r>l)
             max=std::max(max,(r-l)*(height[l]>height[r]?height[r--]:height[l++]));
         return max;
     }
 };