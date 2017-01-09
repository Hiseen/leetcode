class WordDictionary {
 public:
 	template<int Size>
 	class TrieNode
 	{
 	public:
 		int count;
 		TrieNode<Size>* children[Size];
 		bool IsEnd;
 		TrieNode(int index = -1) : count(0)
 		{
 			for (int i = 0; i < Size; ++i)
 				children[i] = nullptr;
 			if (index != -1)children[index] = new TrieNode();
 			IsEnd = false;
 		}
 		bool Search(const string& word, int index)
 		{
 			if (index >= word.length())return false;
 			char temp = word[index];
 			if (temp == '.')
 			{
 				for (int i = 0; i<26; i++)
 					if (children[i])
 					{
 						if (index == word.length() - 1 && children[i]->IsEnd)
 							return true;
 						else if (children[i]->Search(word, index + 1))
 							return true;
 					}
 			}
 			else
 			{
 				if (children[temp - 'a'])
 				{
 					if (index == word.length() - 1)
 						return children[temp - 'a']->IsEnd;
 					else return children[temp - 'a']->Search(word, index + 1);
 				}
 			}
 			return false;
 
 		}
 		inline TrieNode<Size>* GetSubNode(int index)
 		{
 			assert(index < Size);
 			return children[index];
 		}
 		TrieNode<Size>* insert(int index)
 		{
 			TrieNode<Size> *node = GetSubNode(index);
 			if (!node)
 				node = new TrieNode();
 			node->count++;
 			children[index] = node;
 			return node;
 		}
 		~TrieNode()
 		{
 			for (int i = 0; i < Size; ++i)
 			{
 				if (children[i])
 				{
 					delete children[i];
 					children[i] = nullptr;
 				}
 			}
 		}
 	};
 	template<int Size>
 	class Trie
 	{
 	public:
 		Trie()
 		{
 			root = new TrieNode<Size>();
 		};
 		void Insert(const string& s)
 		{
 			auto node = root;
 			int len = s.size();
 			for (int i = 0; i < len; ++i)
 				node = node->insert(s[i] - 'a');
 			node->IsEnd = true;
 		}
 
 		~Trie()
 		{
 			if (root)
 				delete root;
 		};
 		TrieNode<Size>* root;
 	};
 	Trie<26> t;
 
 	// Adds a word into the data structure.
 	void addWord(string word) {
 		t.Insert(word);
 	}
 
 	// Returns if the word is in the data structure. A word could
 	// contain the dot character '.' to represent any one letter.
 	bool search(string word) {
 		bool temp=t.root->Search(word,0);
 		cout << temp << endl;
 		return temp;
 
 	}
 };