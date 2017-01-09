class TrieNode {
 public:
     // Initialize your data structure here.
     TrieNode** children;
     bool End;
     TrieNode() {
         children=new TrieNode*[26];
         for(int i=0;i<26;i++)
         children[i]=nullptr;
         End=false;
     }
     ~TrieNode()
     {
         for(int i=0;i<26;i++)
         if(children[i])delete children[i];
         delete children;
     }
 };
 
 class Trie {
 public:
     Trie() {
         root = new TrieNode();
     }
 
     // Inserts a word into the trie.
     void insert(string word) {
         auto n=root;
         int i=0;
         int max=word.length();
         while(i<max)
         {
             if(n->children[word[i]-'a']==nullptr)
                 n->children[word[i]-'a']=new TrieNode();
             n=n->children[word[i]-'a'];
             i++;
         }
         n->End=true;
     }
 
     // Returns if the word is in the trie.
     bool search(string word) {
         auto n=root;
         int i=0;
         int max=word.length();
         while(i<max)
         {
             if(n->children[word[i]-'a']==nullptr)
                 return false;
             n=n->children[word[i]-'a'];
             i++;
         }
         return n->End;
     }
 
     // Returns if there is any word in the trie
     // that starts with the given prefix.
     bool startsWith(string prefix) {
         auto n=root;
         int i=0;
         int max=prefix.length();
         while(i<max)
         {
             if(n->children[prefix[i]-'a']==nullptr)
                 return false;
             n=n->children[prefix[i]-'a'];
             i++;
         }
         return true;
     }
 
 private:
     TrieNode* root;
 };
 
 // Your Trie object will be instantiated and called as such:
 // Trie trie;
 // trie.insert("somestring");
 // trie.search("key");