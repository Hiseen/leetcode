class Solution {
 public:
     void r(int *a,int index,int n,int& count)
     {
     	if (index != n+1)
     	{
     		for (int i = 0; i < n; i++)
     		{
     			for (int j = index - 1; j>0; j--)
     			{
     				int p = a[j];
     			    if(i == p || i == p-index+j || i==p+index-j)
     				    goto R;
     			}
     			a[index] = i;
     			r(a, index + 1,n,count);
     		R:;
     		}
     	}
     	else
     		count++;
     };
     int totalNQueens(int n) {
         int count=0;
         int* a=new int[n+1];
         r(a,1,n,count);
         return count;
     }
 };