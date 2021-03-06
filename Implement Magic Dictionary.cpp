class MagicDictionary {
public:
    struct TrieNode
    {
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
    
    bool isMagical(TrieNode* root,const string& str)
    {
        for(int i=0;i<str.size();++i)
        {
            for(int j=0;j<26;++j)
            {
                if(str[i]-'a'!=j && root->child[j]!=nullptr && Find(root->child[j],str,i+1))
                    return true;
            }
            if(root->child[str[i]-'a']==nullptr)return false;
            root=root->child[str[i]-'a'];
        }
        return false;
    }
    
    
    
    bool Find(TrieNode* root,string str,int start=0)
    {
        TrieNode* now=root;
        for(int i=start;i<str.size();++i)
        {
            if(now->child[str[i]-'a']!=nullptr)
            {
                now=now->child[str[i]-'a'];
            }
            else
                return false;
        }
        return now->isEnd;
    }
    
    
    /** Initialize your data structure here. */
    MagicDictionary() {
        root=new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto i: dict)
        {
            auto t=root;
            for(int j=0;j<i.size();++j)
            {
                t=t->Add(i[j]);
            }
            t->isEnd=true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return isMagical(root,word);
    }
    
    ~MagicDictionary()
    {
        delete root;
    }
    
    
private:
    TrieNode* root;
    
    
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */