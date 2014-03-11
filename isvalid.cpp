#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
 bool isValid(string s) {
       stack<char> ss;
       for(int i=0;i<s.size();i++)
       {
           switch(s[i])
           {
               case '(':
               {
                   ss.push('(');
                   break;
               }
               case '{':
               {
                   ss.push('{');
                   break;
               }
               case '[':
               {
                   ss.push('[');
                   break;
               }
               case ')':
               {   
                   if(ss.empty() || ss.top()!='(')
                   return false;
                   else ss.pop();
                   break;
               }
                case '}':
               {    
                   
                   if(ss.empty() || ss.top()!='{')
                   return false;
                   else ss.pop();
                   break;
               }
                case ']':
               {
                   if(ss.empty() || ss.top()!='[')
                   return false;
                   else ss.pop();
                   break;
               }
           }
       }
       return ss.empty();
    }
int main()
{
	string s="()"; 
	cout<< isValid(s)<<endl; 
}
