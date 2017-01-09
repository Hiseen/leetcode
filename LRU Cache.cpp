class LRUCache {
 	class ListNode
 	{
 	public:
 		ListNode(int i, ListNode* n)
 		{
 			info = i;
 			next = n;
 			pre = nullptr;
 		}
 		int info;
 		ListNode* next;
 		ListNode* pre;
 		int size;
 		~ListNode()
 		{
 			if (next)
 				delete next;
 		}
 	};
 	int Capacity;
 	map<int, pair<int, ListNode*>> data;
 	ListNode* head;
 	ListNode* tail;
 	int count;
 public:
 	LRUCache(int capacity) {
 		Capacity = capacity;
 		count = 0;
 		head = nullptr;
 		tail = nullptr;
 	}
 
 	~LRUCache()
 	{
 		delete head;
 	}
 
 	int get(int key) {
 		if (data.find(key) != data.end())
 		{
 			const pair<int, ListNode*>& temp = data[key];
 			ListNode* ln = temp.second;
 			if (ln != head)
 			{
 				if (ln == tail)
 				{
 					ln->pre->next = nullptr;
 					tail = ln->pre;
 				}
 				if (ln->pre)ln->pre->next = ln->next;
 				if (ln->next)ln->next->pre = ln->pre;
 				head->pre = ln;
 				ln->next = head;
 				head = ln;
 			}
 			return temp.first;
 		}
 		else
 			return -1;
 	}
 
 	void set(int key, int value) {
 		if (data.find(key) == data.end())
 		{
 			if (head)
 			{
 				ListNode* t = head;
 				head = new ListNode(key, head);
 				t->pre = head;
 			}
 			else
 			{
 				head = new ListNode(key, head);
 				tail = head;
 			}
 			data[key] = make_pair(value, head);
 		}
 		else
 		{
 			data[key].first = value;
 			ListNode* ln = data[key].second;
 			if (ln != head)
 			{
 				if (ln == tail)
 				{
 					ln->pre->next = nullptr;
 					tail = ln->pre;
 				}
 				if (ln->pre)ln->pre->next = ln->next;
 				if (ln->next)ln->next->pre = ln->pre;
 				head->pre = ln;
 				ln->next = head;
 				head = ln;
 			}
 			return;
 		}
 		count++;
 		if (count>Capacity)
 		{
 			data.erase(data.find(tail->info));
 			ListNode* temp = tail;
 			tail = tail->pre;
 			if (tail)tail->next = nullptr;
 			delete temp;
 			count--;
 		}
 	}
 };