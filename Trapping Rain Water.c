int trap(int* height, int heightSize) {
     int l=0,r=heightSize-1,res=0;
     int lh=0, rh=0;
     while(l<r)
     {
         if(height[l]<height[r])
         {
             if(height[l]>lh)
                 lh=height[l];
             else
                 res+=lh-height[l];
             l++;
         }
         else
         {
             if(height[r]>rh)
                 rh=height[r];
             else
                 res+=rh-height[r];
             r--;
         }
     }
     return res;
 }