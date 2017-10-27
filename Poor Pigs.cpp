class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int k=minutesToTest/minutesToDie+1;
        int res=0;
        while(pow(k,res)<buckets)++res;
        return res;
    }
};