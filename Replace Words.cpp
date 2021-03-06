class Solution {
public:
    class TrieNode
    {
    public:
        TrieNode* child[26];
        bool isEnd=false;
        TrieNode* Add(const char& c)
        {
            if(child[c-'a']==nullptr)
                child[c-'a']=new TrieNode();
            return child[c-'a'];
        }
        ~TrieNode()
        {
            for(int i=0;i<26;++i)
            {
                if(child[i]!=nullptr)
                    delete child[i];
            }
        }
    };
    
    string Find(TrieNode* root,string str)
    {
        TrieNode* now=root;
        for(int i=0;i<str.size();++i)
        {
            if(now->isEnd)return str.substr(0,i);
            if(now->child[str[i]-'a']!=nullptr)
            {
                now=now->child[str[i]-'a'];
            }
            else
                return str;
        }
        return str;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* root=new TrieNode();
        for(auto i:dict)
        {
            TrieNode* t=root;
            for(int j=0;j<i.size();++j)
            {
                t=t->Add(i[j]);
            }
            t->isEnd=true;
        }
        
        istringstream iss(sentence);
        vector<string> v;
        copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(v));
        string result=Find(root,v[0]);
        for(int i=1;i<v.size();++i)
        {
            result+=" "+Find(root,v[i]);
        }
        delete root;
        return result;
        
    }
};