#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;
const int INF=0x7fffffff;
#define maxn INF
int n,m;
int puzz[10][10];
int sx,sy;
int time[10][10];
int road[10][10];
int res;
void dfs(int x,int y,int tim,int step)
{
    if(x<0||y<0||x>=n||y>=m)return;//越界
    if(tim<=0||step>=res)return;//炸死或者当前解差于最优解。
    if(puzz[x][y]==0)return;//不能走
    if(puzz[x][y]==3)//到达3
    {
        if(res>step)
            res=step;
    }
    if(puzz[x][y]==4)
      tim=6;
    if(time[x][y]>=tim&&step>=road[x][y])//通过数组来判断一个点是否经过了多次。什么才算第2次经过呢？很显然应该是当前路径经过该点的长度比该点之前的路径的数组记录长，并且剩余时间也应该大于第一次才不剪掉。
        return;
    time[x][y]=tim;
    road[x][y]=step;
    dfs(x,y+1,tim-1,step+1);
    dfs(x,y-1,tim-1,step+1);
    dfs(x+1,y,tim-1,step+1);
    dfs(x-1,y,tim-1,step+1);
    return;
}
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            cin>>puzz[i][j];
            if(puzz[i][j]==2)
            {
                sx=i;
                sy=j;
            }
            road[i][j]=INT_MAX;
        }
        memset(time,0,sizeof(time));
        res=maxn;
        dfs(sx,sy,6,0);
        if(res==maxn)
            cout<<-1<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}
