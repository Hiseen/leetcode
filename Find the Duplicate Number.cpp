class Solution {
 public:
     int size;
     int left_child(int i){return (i+1)*2-1;}
 
     void max_heapify(vector<int>& nums,int i)
     {
         int l=left_child(i);
         int r=l+1;
         int t=i;
         if(l<size && nums[t]<nums[l])
             t=l;
         if(r<size && nums[t]<nums[r])
             t=r;
         if(t!=i)
         {
             int temp=nums[t];
             nums[t]=nums[i];
             nums[i]=temp;
             max_heapify(nums,t);
         }
     }
 
 
     int findDuplicate(vector<int>& nums) {
         size=nums.size();
         for(int i=size/2;i>=0;--i)
             max_heapify(nums,i);
         int last=nums[0];
         swap(nums[0],nums[--size]);
         max_heapify(nums,0);
         while(size)
         {
             if(last==nums[0])
                 return last;
             else
             {
                last=nums[0];
                swap(nums[0],nums[--size]);
                max_heapify(nums,0);
             }
         }
         return last;
         
         
     }
 };