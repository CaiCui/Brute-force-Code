/*
 *题目见Floyd+dfs+cuttingProblem.pdf
 */
//map[i,j]=min{map[i,k]+map[k,j],map[i,j]}
//分支定界+Floyd算法求解最短路径
//利用Floyd求出任意两点间最小的cost和两点间最短的路径，定界
//answer: cost 1448 dis 464
//Author:Cuiyifeng 2016-12-16
//实现语言:C语言
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 1000000
#define minn -1000000
int roadpath[100][100];
int cost[100][100];
const int totalcost=1500;
int rd[1000][1000],rpath[1000][1000];//记录一下每条路径下届
int cd[1000][1000],cpath[1000][1000];//记录一下每条路径花费下届
int dismin;//最短距离
int costmin;//最短距离下的花费
int vis[55];
int tmppath[55];//记录最短路径的走法;
int path[55];
void solve(int x,int dis,int costnow,int k)//求出从roadpath[0][0],roadpath[49][49]的在cost<=1500的最短路径
{
    if(x==50)
    {
        if(dis<dismin)
        {
            tmppath[k]=x;
            dismin = dis;
            costmin = costnow;
            memcpy(path,tmppath,sizeof(tmppath));
        }
    }
    else
    {

      if(costnow+cd[x][50]>totalcost)return;//剪枝1：当前路径的花费+走完剩余路径的最小花费也大于1500则剪去
      if(rd[x][50]<9999&&dis+rd[x][50]>dismin)return;//剪枝2：当前路径的距离+走完剩余路径的最短路径也大于当前dismin则剪去
      for(int i=1;i<=50;i++)
      {
          if(i==x)continue;

          if(roadpath[x][i]<9999&&roadpath[x][i]+dis<dismin&&!vis[i]&&costnow+cost[x][i]<totalcost)//剪枝3：当前花费加上下一步要走的距离<1500 4:当前路径加上下一个路径<当前dismin
          {

              vis[i]=1;
              tmppath[k]=x;
              solve(i,dis+roadpath[x][i],costnow+cost[x][i],k+1);
              vis[i]=0;
          }

      }
    }

}
void coutLowBound()//Fylod求出每条路径的下界和每条路径花费的下界
{
      int i,j,k;
      for(i=1;i<=50;i++)
        for(j=1;j<=50;j++){
            rd[i][j]=roadpath[i][j];
            //rpath[i][j]=j;
      }
      for(k=1;k<=50;k++)
        for(i=1;i<=50;i++)
            for(j=1;j<=50;j++)
            {
                if(rd[i][k]+rd[k][j]<rd[i][j]){
                    rd[i][j]=rd[i][k]+rd[k][j];
                    //rpath[i][j]=rpath[i][k];
                }
            }

     for(i=1;i<=50;i++)
        for(j=1;j<=50;j++){
            cd[i][j]=cost[i][j];
            //cpath[i][j]=j;
      }
      for(k=1;k<=50;k++)
        for(i=1;i<=50;i++)
            for(j=1;j<=50;j++)
            {

                if(cd[i][k]+cd[k][j]<cd[i][j]){
                    cd[i][j]=cd[i][k]+cd[k][j];
                    //cpath[i][j]=cpath[i][k];
                }
            }


}
int main()
{

    freopen("m1.in","r",stdin);//读入m1
    memset(roadpath, 0, sizeof(roadpath));
    memset(cost, 0, sizeof(cost));
    for(int i = 1; i <= 50; i++)
      for(int j = 1; j <= 50; j++)
        scanf("%d", &roadpath[i][j]);

    freopen("m2.in","r",stdin);//读入m2
    for(int i = 1; i <= 50; i++)
      for(int j = 1; j <= 50; j++)
        scanf("%d", &cost[i][j]);
    dismin = maxn;
    memset(vis,0,sizeof(vis));
    coutLowBound();//计算下界
    solve(1,0,0,0);//深搜+剪枝
    printf("从甲到乙的最短路径距离是: %d 花费是: %d\n",dismin,costmin);
    printf("路径是：");
    for(int i=0;;i++)
        {
            if(path[i]==50)break;
            printf("%d->",path[i]);
        }
    printf("50\n");
    return 0;

}
