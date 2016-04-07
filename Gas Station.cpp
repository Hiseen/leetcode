class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int index=-1,size=gas.size(),max=0,max2=0;
        for(int i=0;i<size;++i)
        {
            int temp=gas[i]-cost[i];
            max+=temp;
            max2+=temp;
            if(max<0){max=0;index=i+1;}
        }
        return (max2>=0 && index==-1)?0:max2<0?-1:index;
    }
};