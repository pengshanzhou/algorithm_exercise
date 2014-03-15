class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        const int gap=0-'0';
        stack<int> s;
        int x,y;
        for(int i=0;i<tokens.size();i++)
        {
         
            if(tokens[i]=="-")
            {
                x=s.top();
                s.pop();
                y=s.top();
                s.pop();
                s.push(y-x);
            }
            else if(tokens[i]=="+")
            {
                x=s.top();
                s.pop();
                y=s.top();
                s.pop();
                s.push(x+y);
            }
            else if(tokens[i]=="*")
            {
                x=s.top();
                s.pop();
                y=s.top();
                s.pop();
                s.push(y*x);
                
            }
            else if(tokens[i]=="/")
            {
                x=s.top();
                s.pop();
                y=s.top();
                s.pop();
                s.push(y/x);
                
            }
            else s.push(atoi(tokens[i].c_str()));
           
        }
         return s.top();
    }
};
