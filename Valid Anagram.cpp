class Solution {
public:
    bool isAnagram(string s, string t) {
	if (s.size() != t.size())
		return false;
	int result[26];
	memset(result,0,sizeof(result));
	for (int i = 0;i<s.size();i++)
	{
	    result[s[i]-97]++;
	    result[t[i]-97]--;
	}
	
	for(int i=0;i<26;i++)
	{
	    if(result[i])
	        return false;
	}
	return true;
}
};