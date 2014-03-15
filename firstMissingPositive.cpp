class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n==0)
        return 1;
       int *b=new int[n+1];
       for(int i=0;i<=n;i++)
       {
           b[i]=1;
       }
       for(int i=0;i<n;i++)
       {
           if(A[i]>0 && A[i]<=n)
           b[A[i]-1]=0;
       }
       int i=0;
       while( i<n && b[i]==0)
       {
           i++;
       }
       delete[] b;
       b=NULL;
       return i+1;
       
    }
};




