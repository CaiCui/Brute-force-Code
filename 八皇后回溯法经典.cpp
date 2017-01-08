#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
///复习八皇后
#define maxn 100
int n;
int tot;
int A[maxn];
int vis[maxn][maxn];
/*
void eight(int k)///k就是行数，而循环枚举的i是列数
{
    if(k==n)
        tot++;
    else
    {

        for(int i=0;i<n;i++)
        {
            int ok=1;
            A[k]=i;
            for(int j=0;j<k;j++)
              if(A[j]==A[k]||k+A[k]==A[j]+j||A[k]-k==A[j]-j)
                {ok=0;break;}
              if(ok)
                eight(k+1);

        }
    }
}*/
void eight(int k)
{
    if(k==n)
        tot++;
    else
    {   int i;
        for( i=0;i<n;i++)
        {
            if(!vis[0][i]&&!vis[1][k+i]&&!vis[2][k-i+n])
            {
                A[k]=i;
                vis[0][i]=vis[1][k+i]=vis[2][k-i+n]=1;
                eight(k+1);
                vis[0][i]=vis[1][k+i]=vis[2][k-i+n]=0;
            }
        }
    }
}
int main()
{
   cin>>n;
   tot=0;
   memset(vis,0,sizeof(vis));
   eight(0);
   cout<<tot<<endl;
   return 0;
}
