class Solution {
public:
bool wordPattern(string pattern, string str) {
	int nowpos = 0, prepos = 0;
	if (str.find(' ', 0) == -1)
		return pattern.size() == 1;
	string hashtable[26];
	for (int i = 0;i<26;i++)
		hashtable[i] = "";
	for (int i = 0;i<pattern.size();i++)
	{
		int index = pattern[i] - 97;
		if (hashtable[index] == "")
		{
			nowpos = str.find(' ', prepos);
			string temp = str.substr(prepos, nowpos - prepos);
			hashtable[index] = temp;
			for (int j = index - 1;j >= 0;j--)
			{
				if (hashtable[j] == temp)
					return false;
			}
		}
		else
		{
			nowpos = str.find(' ', prepos);
			string temp = str.substr(prepos, nowpos - prepos);
			if (hashtable[index] != temp)
				return false;
			else
			{
				for (int j = index - 1;j >= 0;j--)
				{
					if (hashtable[j] == temp)
						return false;
				}

			}
		}
		prepos = nowpos + 1;
	}
	if (nowpos != -1)
		return false;
	return true;

}
};