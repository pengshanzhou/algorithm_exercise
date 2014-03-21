class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int long long s;
        sort(S.begin(),S.end());
        vector< vector <int> > result;
       
        //result.push_back(tem);
        vector<int> re(S.size(),0);
        s=pow(2,S.size());

        for(long long k=0;k<s;k++)
        {
            vector<int> tem;
            int n=0,m=0;
            int i=k; // 这一步一开始写错。。。
            while(i>0)
            {
                //n++;
                re[n++]=i%2;
                i=i/2;
            }
            for(int j=0;j<n;j++)
            {
                if(re[j]==1)
                tem.push_back(S[j]);
            }
            result.push_back(tem);
            //re.resize(0);
            //tem.resize(0);
        }
        return result;
    }
};
