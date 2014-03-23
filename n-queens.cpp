class Solution {
public:
    vector<vector<string>> slove;
    bool place(int k,vector<int> &x)
    {
        int i = 0;
       while( i < k)
        {
           if( x[i]==x[k] || (abs(x[i]-x[k]) == abs(i-k)) )
             return false;
         i++;
       }
       return true;
    }
    vector<vector<string> > solveNQueens(int n) {
        vector <int> x(n,0);
        int k=0;
        //x[0]=0;
        x[0]=0;
        while(x[0]!=n+1)
        {
            do{
                x[k]=x[k]+1;
            }while(!place(k,x) && x[k]<n+1);
            
            if(x[k]==n+1)
            { 
                if(k==0)
                goto end;
                else 
                {
                    x[k]=0;
                    k--;
                    
                }
            }
            else
            {
             if(k==n-1)
               {
                   vector<string>temp;
                   for(int i=0;i<n;i++)
                   {
                       string s(n,'.');
                       s[x[i]-1]='Q';
                       temp.push_back(s);
                   }
                   slove.push_back(temp);
               }
             else 
               k++;
            }
        }
        end:return slove;
    }
};
