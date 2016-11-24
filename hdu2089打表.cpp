//hdu2089 不要62 区间计数 打表，否则直接计算(n,m)会TLE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<climits>
#include<deque>
#include<stack>
#include<vector>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<functional>
#include<cstring>
#include<cctype>
#include<bits/stdc++.h>
typedef long long ll;
const int MOD=10e9+7;
const int INF=0x7fffffff;
const double ESP=10e-7;
const double Pi=acos(-1.0);
const int dr[]= {0,0,1,-1,1,1,-1,-1};
const int dc[]= {-1,1,0,0,-1,1,-1,1};
#define maxn INF
#define min -INF
using namespace std;
int f[1000000];
int calc(int i)
{
    int temp,tmp;
    temp=-1;
    while(i)
    {
        tmp=i%10;
        if(tmp==4)
            return 1;
        if(tmp==6)
        {
            if(temp==2)
                return 1;
        }
        i=i/10;
        temp=tmp;
    }
    return 0;
}
int main(void)
{   int n,m,i,res;
    for(i=1;i<=1000000;i++)
      f[i]=calc(i);
    while(scanf("%d%d",&n,&m)&&m*m+n*n!=0)//从这里开始算时间，所以离线处理下就好了
    {
        res=0;
        for(i=n;i<=m;i++)
           res+=f[i];
        printf("%d\n",m-n+1-res);
    }
    return 0;
}

/*
利用前缀和，做减法也可以，即[2,10]=S[10]-s[2-1];
int a[1000010],i,j,n,m;
char num[1000010];

int main(){
  memset(a,0,sizeof(0));
  for(i=1;i<=1000001;i++){
   itoa(i,num,10);
   if(strstr(num,"4")!=NULL){a[i]+=a[i-1]+1; continue;}
   if(strstr(num,"62")!=NULL){a[i]+=a[i-1]+1; continue;}
   a[i]=a[i-1];
  }
  scanf("%d%d",&n,&m); int sum,ans;
  while(n!=0&&m!=0){
   sum=m-n+1;
   ans=sum-(a[m]-a[n-1]);
   printf("%dn",ans);
   scanf("%d%d",&n,&m);
  }
  return 0;
}
*/
