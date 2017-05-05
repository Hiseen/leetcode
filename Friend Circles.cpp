class Solution {
 public:
     class UF  
     {  
         public:
         int* id; 
         int count;
         int len;
         UF(int N)  
         {  
             count = N;  
             id = new int[N];
             len=N;
             for (int i = 0; i < N; i++)  
                 id[i] = i;  
         }  
         int getcount()  
         { return count; }  
         bool connected(int p, int q)  
         { return find(p) == find(q); }  
         int find(int p)  
         { return id[p]; }  
         void connect(int p, int q)  
         {   
             int pID = find(p);  
             int qID = find(q);  
             if (pID == qID) return;  
             for (int i = 0; i <len; i++)  
                 if (id[i] == pID) id[i] = qID;  
             count--;  
         }  
     } ;
     int findCircleNum(vector<vector<int>>& M) {
         UF friends(M.size());
         for(int i=0;i<M.size();++i)
         for(int j=i;j<M.size();++j)
         {
             if(M[i][j])
                 friends.connect(i,j);
         }
         return friends.getcount();
     }
 };