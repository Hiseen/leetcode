class Solution {
 public:
     int lengthOfLongestSubstring(string s) {
     	if (s.size()<2)
     		return s.size();
     	int hash[256];
     	bool flag = false;
     	int index = 0;
     	memset(hash, -1, sizeof(hash));
     	int size = s.size();
     	int maxcount = 0, temp = 0;
     	for (int i = 0;i<size;++i)
     	{
     		if (hash[s[i]] == -1)
     			temp++;
     		else
     		{
     		    if (temp>maxcount)
     				maxcount = temp;
     			if (index<=hash[s[i]])
     			{
     				temp = i - hash[s[i]];
     				index = hash[s[i]]+1;
     			}
     			else
     				temp++;
     		}
     		hash[s[i]] = i;
     	}
     	return maxcount>temp ? maxcount : temp;
     }
 };