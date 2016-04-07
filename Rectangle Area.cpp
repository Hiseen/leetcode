class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area=(C-A)*(D-B)+(G-E)*(H-F);
        int n1=max(A,E);
        int n2=max(B,F);
        int n3=min(C,G);
        int n4=min(D,H);
        if(n1>n3 || n2>n4)
           return area;
           else
           return area+(n3-n1)*(n2-n4);
        
        
        
        
    }
};