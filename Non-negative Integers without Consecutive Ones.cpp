class Solution { 
public: 
    bool has11(int num) 
    { 
        bool check=false; 
        for(int i=0;i<32;i++) 
        { 
            if(num>>i & 1) 
                if(check)return true; 
                else check=true; 
            else 
                check=false; 
        } 
        return false; 
    } 
 
    int findIntegers(int num) { 
        if(num==0)return 1; 
        if(num==1)return 2; 
        int res=recur(num,num); 
        if(!has11(num))return res+1; 
        return res; 
    } 
     
    int recur(int num,int max) 
    { 
        //cout<<num<<" "<<max<<endl; 
        if(num==0)return 0; 
        if(num==1)return 1; 
        int i=0; 
        int res=2; 
        int first=1; 
        int second=1; 
        long b=4; 
        while(b<=max) 
        { 
            res+=second; 
            int temp=second; 
            second+=first; 
            first=temp; 
            b*=2; 
        } 
        b/=2; 
        num-=b; 
        int m=b/2>num?num:b/2; 
        return res+recur(m,m); 
    } 
};