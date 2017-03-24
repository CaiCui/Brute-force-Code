#include <iostream>
#include<cstring>
using namespace std;
///1~n全排列枚举
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
 ///输入一个序列给定全排列,无字典序,从右往左枚举,思路把后面扩展的每一个数与当前k交换一次
   else{
      for(int j=k;j<n;j++)
       {
          swap(a[k],a[j]);
          allpaixu(a,n,k+1);
          swap(a[k],a[j]);
       }

}
*/
else ///直接给出1~n字典序全排列,前缀枚举
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
