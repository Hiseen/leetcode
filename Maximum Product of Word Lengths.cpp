class Solution {
 public:
 
     int trans(const string& word)
     {
         int res=0;
         for(auto i:word)
         {
             res|=1<<i-97;
         }
         return res;
     }
 
 
 
     int maxProduct(vector<string>& words) {
         vector<int> numbers;
         vector<int> lengths;
         int size=words.size();
         numbers.resize(size,0);
         lengths.resize(size,0);
         int count=0;
         for(auto i:words)
         {
             lengths[count]=i.length();
             numbers[count++]=trans(i);
         }
         
         int max=0;
         for(int i=0;i<size;++i)
         {
             for(int j=i+1;j<size;++j)
                 if((numbers[i]&numbers[j])==0)
                 {
                     int temp=lengths[i]*lengths[j];
                     if(temp>max)max=temp;
                 }
         }
         return max;
         
     }
 };