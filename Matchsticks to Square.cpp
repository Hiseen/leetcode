class Solution {
 public:
 
 
     bool dfs(vector<int>& parts,int index,const vector<int>& nums,int target)
     {
         if(index==nums.size())return parts[0]==target && parts[1]==target && parts[2]==target;
         for(int i=0;i<4;++i)
         {
             if(parts[i]+nums[index]<=target)
             {
                 bool exitflag=false;
                 for(int j=i-1;j>=0;j--)
                     if(parts[j]==parts[i])
                     {
                         exitflag=true;
                         break;
                     }
                 if(exitflag)continue;
                 parts[i]+=nums[index];
                 if(dfs(parts,index+1,nums,target))
                     return true;
                 parts[i]-=nums[index];
             }
         }
         return false;
     }
 
 
     bool makesquare(vector<int>& nums) {
         int size=nums.size();
         if(size<4)return false;
         if(size==4)
         {
             for(int i=0;i<3;++i)
                 if(nums[i]!=nums[i+1])return false;
             return true;
         }
         int sum=0;
         for(int i=0;i<size;++i)
             sum+=nums[i];
         if(sum%4!=0)return false;
         sort(nums.begin(),nums.end());
         int target=sum/4;
         vector<int> parts(4,0);
         return dfs(parts,0,nums,target);
     }
 };