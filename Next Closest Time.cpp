class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<int> d;
        int it=0;
        for(int i=0;i<5;++i)
        {
            if(i!=2)
            {
                d.insert(time[i]-'0');
                it+=time[i]-'0';
                it*=10;
            }
        }
        it/=10;
        if(d.size()==1)return time;
        int now=it+1;
        while(now!=it)
        {
            if(now%100==60){now/=100;++now;now*=100;}
            if(now==2400)now=0;
            int temp=now;
            bool flag=false;
            for(int i=0;i<4;++i)
            {
                if(d.find(temp%10)==d.end()){flag=true;break;}
                temp/=10;
            }
            if(!flag)break;
            ++now;
        }
        string res=to_string(now);
        res.insert(0,4-res.size(),'0');
        res.insert(2,1,':');
        return res;
        
    }
};