#include <iostream>
#include<cstring>
using namespace std;
///1~nȫ����ö��
#define maxn 100
int A[maxn];
void allpaixu(int a[],int n,int k)
{
    if(k==n)
    {
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    /*
 ///����һ�����и���ȫ����,���ֵ���,��������ö��,˼·�Ѻ�����չ��ÿһ�����뵱ǰk����һ��
   else{
      for(int j=k;j<n;j++)
       {
          swap(a[k],a[j]);
          allpaixu(a,n,k+1);
          swap(a[k],a[j]);
       }

}
*/
else ///ֱ�Ӹ���1~n�ֵ���ȫ����,ǰ׺ö��
    for(int i=1;i<=n;i++)
{
    int ok=1;
    for(int j=0;j<k;j++)
        if(A[j]==i)
          ok=0;
    if(ok)
    {
         A[k]=i;
         allpaixu(a,n,k+1);
    }
}

}
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
    cin>>A[i];
   allpaixu(A,n,0);
   return 0;
}
