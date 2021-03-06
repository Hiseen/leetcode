class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res=0;
        int i=0;
        vector<int> ints;
        while(i<ops.size())
        {
            if(ops[i]=="+")
            {
                auto iter=ints.rbegin();
                int temp=*iter++;
                temp+=*iter;
                res+=temp;
                ints.push_back(temp);
            }
            else if(ops[i]=="C")
            {
                res-=*ints.rbegin();
                ints.pop_back();
            }
            else if(ops[i]=="D")
            {
                int temp=*ints.rbegin()*2;
                res+=temp;
                ints.push_back(temp);
            }
            else
            {
                int temp=atoi(ops[i].c_str());
                res+=temp;
                ints.push_back(temp);
            }
            ++i;
        }    
        return res;
    }
};