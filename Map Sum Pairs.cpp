class MapSum {
public:
    class TrieNode
    {
    public:
        TrieNode* child[26];
        int val=0;
        bool f=false;
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
    TrieNode* root;
    /** Initialize your data structure here. */
    MapSum() {
        root=new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* t=root;
        int temp;
        for(int j=0;j<key.size();++j)
        {
            t->val+=val;
            t=t->Add(key[j]);
        }
        if(t->f)
        {
            temp=t->val;
            t=root;
            for(int j=0;j<key.size();++j)
            {
                t->val-=temp;
                t=t->child[key[j]-'a'];
            }
            t->val=val;
        }
        else
        {
            t->val+=val;
            t->f=true;
        }
        
    }
    
    
    int sum(string prefix) {
        TrieNode* t=root;
        for(auto i: prefix)
        {
            t=t->child[i-'a'];
            if(!t)return 0;
        }
        return t->val;
        
    }
    ~MapSum()
    {
        delete root;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */