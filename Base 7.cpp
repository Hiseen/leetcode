class Solution { 
public: 
    string convertToBase7(int num) { 
        if(!num)return "0"; 
        bool minus=false; 
        if(num<0) 
        { 
            num=-num; 
            minus=true; 
        } 
        string result=""; 
        while(num) 
        { 
            result.insert(0,1,'0'+num%7); 
            num/=7; 
        } 
        return minus?result.insert(0,1,'-'):result; 
    } 
};