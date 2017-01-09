class Solution {
 public:
     template<int Size>
 	class TrieNode
 	{
 	public:
 		int count;
 		TrieNode<Size>* children[Size];
 		bool IsEnd;
 		string* word;
 		TrieNode(int index = -1) : count(0)
 		{
 		    word=nullptr;
 			assert(index < Size);
 			for (int i = 0; i < Size; ++i)
 				children[i] = nullptr;
 			if (index != -1)children[index] = new TrieNode();
 			IsEnd = false;
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
 		TrieNode<Size>* remove(int index, bool isend = false)
 		{
 			TrieNode<Size>* node = GetSubNode(index);
 			if (node->count == 1)
 			{
 				delete node;
 				node = nullptr;
 				children[index] = nullptr;
 			}
 			else
 			{
 				node->count--;
 				if (isend)node->IsEnd = false;
 			}
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
 		Trie(const function<int(const char)>& f)
 		{
 			root = new TrieNode<Size>();
 			conversion = f;
 		};
 		void Insert(const string& s)
 		{
 			auto node = root;
 			int len = s.size();
 			for (int i = 0; i < len; ++i)
 				node = node->insert(conversion(s[i]));
 			node->IsEnd=true;
 			node->word=new string(s);
 		}
 
 		~Trie()
 		{
 			if (root)
 				delete root;
 		};
 		TrieNode<Size>* root;
 	private:
 		function<int(const char)> conversion;
 	};
     bool** table;
     void Search(vector<vector<char>>& board, int x,int y,TrieNode<26>* n,set<string>& result,int maxx,int maxy)
     {
         if(!n || table[x][y])return;
         if(n->IsEnd)result.insert(*(n->word));
         table[x][y]=true;
         if(x>0)Search(board,x-1,y,n->GetSubNode((int)(board[x-1][y]-'a')),result,maxx,maxy);
         if(x<maxx)Search(board,x+1,y,n->GetSubNode((int)(board[x+1][y]-'a')),result,maxx,maxy);
         if(y>0)Search(board,x,y-1,n->GetSubNode((int)(board[x][y-1]-'a')),result,maxx,maxy);
         if(y<maxy)Search(board,x,y+1,n->GetSubNode((int)(board[x][y+1]-'a')),result,maxx,maxy);
         table[x][y]=false;
     }
 
 
 
     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         Trie<26> t([](const char c) {return (int)(c - 'a'); });
         for(int i=0;i<words.size();i++)
             t.Insert(words[i]);
         set<string> result;
         int boardh=board.size();
         int boardw=board[0].size();
         size_t s=sizeof(bool)*boardw;
         table=new bool*[boardh];
         for(int i=0;i<boardh;i++)
         {
             table[i]=new bool[boardw];
             memset(table[i],0,s);
         }
         for(int i=0;i<boardh;i++)
         for(int j=0;j<boardw;j++)
         {
             auto temp=t.root->GetSubNode(board[i][j]-'a');
             if(temp)
             {
                 Search(board,i,j,temp,result,boardh-1,boardw-1);
             }
         }
         vector<string> res;
         std::copy(result.begin(),result.end(),std::back_inserter(res));
         return res;
         
     }
 };