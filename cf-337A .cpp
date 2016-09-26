/**
  *Problem 337A - Puzzles
  *直接暴力超时,而且注意dfs的时候千万不要在执行过程中对用到的数组排序,神tm坑...后来才发现排序造成了结果错误
  *改用动态规划....神tm dp.maxx=min(maxx,a[i+n]-a[i]);.....其实是个贪心+排序，坑死了。。。
  *菜的扣脚啊T_T,不过可以考虑下动态规划怎么解，肯定没这种方法快。
  */
#include<bits/stdc++.h>
using namespace std;
#define MIN 1000000
int main()
{
    int m,n,b[60],j,k;
    int minnum;
    minnum=MIN;
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(b,b+m);
    for(j=0;j<m;j++)
    {
        k=j+n-1;
        if(k<m&&b[k]-b[j]<minnum)
            minnum=b[k]-b[j];
    }
    cout<<minnum<<endl;
    return 0;
}


/*TLE
#include<bits/stdc++.h>
using namespace std;
#define MIN 1000000
#define MAX -1000000
int b[60],n,m;
int flag[60];
int minnum;
int fff=0;
bool cmp(int a,int b)
 {
     return a>b?1:0;
 }
void solve(int k,int start,int c[])
{

    if(k==n&&!fff)
    {
        int j;
        int tmpmin,tmpmax;
        tmpmin=MIN;
        tmpmax=MAX;
        //sort(c,c+n,cmp);
    
        for(j=0;j<n;j++)
        {
            if(c[j]<tmpmin)
                tmpmin=c[j];
            if(c[j]>tmpmax)
                tmpmax=c[j];
        }

        if(tmpmax-tmpmin<minnum)
            minnum=tmpmax-tmpmin;
        if(minnum==0)
            fff=1;


    }
    else
    {
        if(!fff)
        {
              int i;
        for(i=start;i<m;i++)
            if(!flag[i])
                {
                    flag[i]=1;
                    c[k]=b[i];
                    solve(k+1,i+1,c);
                    c[k]=0;
                    flag[i]=0;
                }
        }

    }
}
int main()
{
    int c[60];
   cin>>n>>m;
   memset(flag,0,sizeof(flag));
   memset(c,0,sizeof(c));
   for(int i=0;i<m;i++)
    cin>>b[i];
    sort(b,b+n,cmp);
   minnum=MIN;
   solve(0,0,c);
   cout<<minnum<<endl;
}

*/


