#include <iostream>
#include<cstring>
using namespace std;
///�Կɸ������ظ����ϵ�ȫ����,ע�������P�����Ѿ��Զ��ź���
#define maxn 100
int A[maxn];
int P[maxn];
void allpaixu(int a[],int b[],int n,int k)
{
  if(k==n)
  {
      for(int i=0;i<n;i++)
      cout<<A[i]<<" ";
      cout<<endl;
  }
  else
  {     int i;
      for(i=0;i<n;i++)
        if(!i||P[i-1]!=P[i])
      {
       int c1,c2;
        c1=c2=0;
       for(int j=0;j<k;j++)
        if(A[j]==P[i])
           c1++;
       for(int j=0;j<n;j++)
        if(P[j]==P[i])
        c2++;
       if(c1<c2)
       {
           A[k]=P[i];
           allpaixu(A,P,n,k+1);
       }
      }
  }
}
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
    cin>>P[i];
   allpaixu(A,P,n,0);
   return 0;
}
