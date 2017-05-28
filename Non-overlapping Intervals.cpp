/**
  * Definition for an interval.
  * struct Interval {
  *     int start;
  *     int end;
  *     Interval() : start(0), end(0) {}
  *     Interval(int s, int e) : start(s), end(e) {}
  * };
  */
 class Solution {
 public:
     int eraseOverlapIntervals(vector<Interval>& intervals) {
         if(intervals.empty())return 0;
         sort(intervals.begin(),intervals.end(),[](const Interval& i1,const Interval& i2){return i1.start<i2.start;});
         int start=intervals[0].start;
         int end=intervals[0].end;
         int res=0;
         for(int i=1;i<intervals.size();++i)
         {
             if(intervals[i].start<end)
             {
                 ++res;
                 if(intervals[i].end<end)
                     end=intervals[i].end;
             }
             else
                 end=intervals[i].end;
         }
         return res;
     }
 };