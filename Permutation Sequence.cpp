class Solution {
public:

    int recur(int n)
    {
        if(n==1)
            return 1;
        else
            return n*recur(n-1);
    }

    string getPermutation(int n, int k) {
        string result="";
        char s[9]={'1','2','3','4','5','6','7','8','9'};
        string str="";
        for(int i=0;i<n;i++)
            str+=s[i];
        k-=1;
    	for (int i=n-1;i>0;i--)
    	{
    		int temp = recur(i);
    		int a = k/temp;
    		result += str[a];
    		str.erase(a, 1);
    		k%=temp;
    	}
    	result+=str;
        return result;
    }
};