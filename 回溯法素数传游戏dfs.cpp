#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
///���������ݷ� ��������ֱ�ӱ���ö��1~n���к����ж�
int n;
int A[20];
bool oo;
bool isprime(int x)
{
    int m;
    m=floor(sqrt(x)+0.5);
    for(int i=2;i<=m;i++)
        if(x%i==0)return false;
    return true;
}
void sushucircle(int k)
{
  if(k==n&&isprime(A[k-1]+A[0]))
    {
        for(int i=0;i<n;i++)
            cout<<A[i]<<" ";
           cout<<endl;
           oo=true;
    }
    else
    {
        int sum;
      for(int i=1;i<=n;i++)
      {
          int ok=1;
          for(int j=0;j<n;j++)
            if(A[j]==i)
              ok=0;
          if(ok)
          {
            A[k]=i;
            if(k!=0)
            sum=A[k]+A[k-1];
            if(isprime(sum)||k==0)
             sushucircle(k+1);
            A[k]=0;///��0����Ҫ!!������һ��ö��
          }
       }
    }
}
int main()
{
while(cin>>n)
  {
    oo=false;
    memset(A,0,sizeof(A));
    sushucircle(0);
   if(!oo)
    cout<<"�޽�!"<<endl;
  }
}
