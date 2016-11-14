
 class Solution {
 public:
     int largestRectangleArea(vector<int>& heights) {
         int size=heights.size();
         if(size==0)return 0;
         int max=0;
         vector<Data> v;
         for(int i=0;i<size;++i)
             v.push_back(Data(i,heights[i]));
         sort(v.begin(),v.end(),[](const Data& l,const Data& r){return l.height<r.height;});
         UnionFind uf(size);
         for(int i=size-1;i>=0;--i)
         {
             Data &b=v[i];
             if(b.index!=0 && b.height<=heights[b.index-1])
                 uf.Union(b.index,b.index-1);
             if(b.index!=size-1 && b.height<=heights[b.index+1])
                 uf.Union(b.index,b.index+1);
             int s=uf.SizeOfSet(b.index);
             if(max<s*b.height)
                 max=s*b.height;
         }
         return max;
     }
 private:
     struct Data
     {
         Data(int i,int h)
         {
             index=i;
             height=h;
         };
         int index;
         int height;
     };
     class UnionFind
     	{
     	public:
     		UnionFind(int size):id(size),sz(size,1)
     		{
     			count = size;
     			for (int i = 0; i < size; ++i)
     				id[i] = i;
     		}
     		inline int Count() { return count; }
     		int Find(int p)
     		{
     			while (p != id[p])
     			{
     				id[p] = id[id[p]];
     				p = id[p];
     			}
     			return p;
     		}
     		inline bool IsConnected(int p, int q)
     		{
     			return Find(p) == Find(q);
     		}
     		inline int SizeOfSet(int p) { return sz[Find(p)]; }
     		void Union(int p, int q)
     		{
     			int rootp = Find(p);
     			int rootq = Find(q);
     			if (rootp == rootq)return;
     			if (sz[rootp] > sz[rootq])
     			{
     				id[rootq] = rootp;
     				sz[rootp] += sz[rootq];
     			}
     			else
     			{
     				id[rootp] = rootq;
     				sz[rootq] += sz[rootp];
     			}
     			count--;
     		}
     		~UnionFind() {};
     	private:
     		vector<int> id;// tree struct
     		vector<int> sz;// store sizes
     		int count;
     	};
 };