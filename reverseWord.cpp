class Solution {
public:
    void reverseWords(string &s) {
        reverse(s,0,s.size());
        int high=-1,low=0;
        while(high<s.size())
        {
            while(s[++high]!=' ' && high<s.size());
        
            if(high==s.size())//边界处理
            {
                reverse(s,low,high-1);// 注意位置指针的变化
                return ;
            }
            else 
            {
                reverse(s,low,high-1);
                low=high+2;
                
            }
        }
    }
    void reverse(string &s, int low,int high)
    {
        while(low<high)
        {
            s[low++]=s[high--];
        }
    }
};
