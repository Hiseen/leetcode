class Solution { 
public: 
    vector<vector<int>> generate(int numRows) { 
        int create=0; 
        vector<vector<int>> res; 
        while(create<numRows) 
        { 
            create++; 
            int now=0; 
            vector<int> a; 
            while(now<create) 
            { 
                if(now!=0 && now!=create-1) 
                   a.push_back(res[create-2][now]+res[create-2][now-1]); 
                   else 
                   a.push_back(1); 
                   now++; 
            } 
            res.push_back(a); 
        } 
        return res; 
         
         
         
         
         
         
         
    } 
};