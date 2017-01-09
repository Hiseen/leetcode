class NumArray {
 public:
 	class BinaryIndexedTree
 	{
 	public:
 		BinaryIndexedTree(int Size, const vector<int>& t)
 		{
 			this->Size = Size;
 			data = new int[Size + 1];
 			for (int i = 0; i <= Size; i++)
 				data[i] = 0;
 			for (int i = 1; i <= Size; ++i)
 			{
 				Modify(i, t[i - 1]);
 			};
 		}
 		int GetSum(int index)
 		{
 			int s = 0;
 			while (index > 0) {
 				s += data[index];
 				index -= lowbit(index);
 			}
 			return s;
 		}
 		void Modify(int index, int d)
 		{
 			while (index <= Size) {
 				data[index] += d;
 				index += lowbit(index);
 			}
 		}
 		~BinaryIndexedTree() { delete data; };
 	private:
 		int lowbit(int x) { return x&(-x); };
 		int* data;
 		int Size;
 	};
 	BinaryIndexedTree a;
 	vector<int> n;
 	NumArray(vector<int> &nums) :a(nums.size(), nums),n(nums) {
 
 	}
 
 	void update(int i, int val) {
 		int temp = val - n[i];
 		n[i]=val;
 		a.Modify(i+1, temp);
 	}
 
 	int sumRange(int i, int j) {
 		return a.GetSum(j + 1)-a.GetSum(i);
 	}
 };
 
 
 // Your NumArray object will be instantiated and called as such:
 // NumArray numArray(nums);
 // numArray.sumRange(0, 1);
 // numArray.update(1, 10);
 // numArray.sumRange(1, 2);