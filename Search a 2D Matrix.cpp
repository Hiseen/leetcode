class Solution {
 public:
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if(matrix.empty() || matrix[0].empty())return false;
         int lo=0, hi=matrix.size()-1;
         if(matrix[hi][0]<target)return binary_search(matrix[hi].begin(),matrix[hi].end(),target);
         while(lo<hi)
         {
             int mid=(hi+lo-1)>>1;
             if(matrix[mid][0]<target)
             {
                 if(matrix[mid+1][0]<=target)
                     lo=mid+1;
                 else
                 {
                     lo=mid;
                     break;
                 }
             }
             else
                 hi=mid;
         }
         cout<<lo<<" "<<hi<<endl;
         return binary_search(matrix[lo].begin(),matrix[lo].end(),target);
     }
 };