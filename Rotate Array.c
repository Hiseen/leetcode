void rotate(int* nums, int numsSize, int k) {
     k%=numsSize;
     int num=numsSize-k;
     int* rotate=NULL;
     rotate=(int*)malloc(sizeof(int)*num);
     int* copy2=NULL;
     copy2=(int*)malloc(sizeof(int)*k);
     memcpy(rotate,nums,num*sizeof(int));
     memcpy(copy2,nums+num,k*sizeof(int));
     memcpy(nums,copy2,k*sizeof(int));
     memcpy(nums+k,rotate,num*sizeof(int));
     
 }