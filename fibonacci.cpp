/*
����fibonacci[n]
*/


/*
����Ҫһ�� ������long long ���� ����AC 
*/
  
#include<iostream>
using namespace std;

long long N,fibonacci[100]={0,1};

int main(){

     for(int i=2;i<=70;++i)
            fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
     while(cin>>N)
            cout<<fibonacci[N]<<endl;
}
