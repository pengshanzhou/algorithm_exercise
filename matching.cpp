#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
bool ismatch(char *src, char *dest)
{
	if(src==NULL || dest == NULL )
	return 0;
	int len1=strlen(src);
	int len2=strlen(dest);	
	if(len1>len2)
	return 0;
	if(len1==0 && len2==0)
	return 0;
	while(*src!=0 && *dest!=0 )
	{
		if(*src==*dest || *src=='?')
		{ 
			++src;
			++dest;
		}
		else if(*src=='*')
		{
			++src;
			while(*dest!= 0)
			{
			  if(ismatch(src,dest++))
		          return 1;
			}
                  break;
		}
		else if(*src != *dest )
		return 0;
	}
	if(*src==0 && *dest==0)
       return 1;
    else return 0;
}	
int main()
{
	char * str[5]={"*","abc","??b","a*b","cd"};
	char * dest[5]={"ahjjk","abc","ssb","asddddb","cc"};
	for(int i=0;i<5;i++)
	{
		cout<<ismatch(str[i],dest[i])<<endl;;	
	}
}
