class Solution {
public:
    int candy(vector<int>& ratings) {
            int result=1,level=1;
            int peak=0,peaklevel=1;
            for(int i=1;i<ratings.size();i++)
            {
                if(ratings[i]<ratings[i-1])
                   {
                    if(level==1)
                       {
                           if(peaklevel>(i-peak))
                              result+=i-peak;
                           else
                              result+=i-peak+1;
                       }
                       else
                       {
                        level=1;
                        result+=1;
                       }
                   }
                   else
                     {
                     if(ratings[i]>ratings[i-1])
                         level++;
                     else
                         level=1;
                     peaklevel=level;
                     peak=i;
                     result+=level;
                     }
            }
               return result;
            
            
        
    }
};