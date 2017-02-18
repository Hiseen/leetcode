int findMaxConsecutiveOnes(int* nums, int numsSize) {
     int now=0;
     int max=0;
     for(int i=0;i<numsSize;++i)
     {
         if(nums[i])
             ++now;
         else
         {
             if(now>max)max=now;
             if(max>=numsSize-i-1)return max;
             now=0;
         }
     }
     return max>now?max:now;
 }