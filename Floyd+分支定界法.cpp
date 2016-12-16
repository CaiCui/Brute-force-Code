/*
 *��Ŀ��Floyd+dfs+cuttingProblem.pdf
 */
//map[i,j]=min{map[i,k]+map[k,j],map[i,j]}
//��֧����+Floyd�㷨������·��
//����Floyd��������������С��cost���������̵�·��������
//answer: cost 1448 dis 464
//Author:Cuiyifeng 2016-12-16
//ʵ������:C����
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
int rd[1000][1000],rpath[1000][1000];//��¼һ��ÿ��·���½�
int cd[1000][1000],cpath[1000][1000];//��¼һ��ÿ��·�������½�
int dismin;//��̾���
int costmin;//��̾����µĻ���
int vis[55];
int tmppath[55];//��¼���·�����߷�;
int path[55];
void solve(int x,int dis,int costnow,int k)//�����roadpath[0][0],roadpath[49][49]����cost<=1500�����·��
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

      if(costnow+cd[x][50]>totalcost)return;//��֦1����ǰ·���Ļ���+����ʣ��·������С����Ҳ����1500���ȥ
      if(rd[x][50]<9999&&dis+rd[x][50]>dismin)return;//��֦2����ǰ·���ľ���+����ʣ��·�������·��Ҳ���ڵ�ǰdismin���ȥ
      for(int i=1;i<=50;i++)
      {
          if(i==x)continue;

          if(roadpath[x][i]<9999&&roadpath[x][i]+dis<dismin&&!vis[i]&&costnow+cost[x][i]<totalcost)//��֦3����ǰ���Ѽ�����һ��Ҫ�ߵľ���<1500 4:��ǰ·��������һ��·��<��ǰdismin
          {

              vis[i]=1;
              tmppath[k]=x;
              solve(i,dis+roadpath[x][i],costnow+cost[x][i],k+1);
              vis[i]=0;
          }

      }
    }

}
void coutLowBound()//Fylod���ÿ��·�����½��ÿ��·�����ѵ��½�
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

    freopen("m1.in","r",stdin);//����m1
    memset(roadpath, 0, sizeof(roadpath));
    memset(cost, 0, sizeof(cost));
    for(int i = 1; i <= 50; i++)
      for(int j = 1; j <= 50; j++)
        scanf("%d", &roadpath[i][j]);

    freopen("m2.in","r",stdin);//����m2
    for(int i = 1; i <= 50; i++)
      for(int j = 1; j <= 50; j++)
        scanf("%d", &cost[i][j]);
    dismin = maxn;
    memset(vis,0,sizeof(vis));
    coutLowBound();//�����½�
    solve(1,0,0,0);//����+��֦
    printf("�Ӽ׵��ҵ����·��������: %d ������: %d\n",dismin,costmin);
    printf("·���ǣ�");
    for(int i=0;;i++)
        {
            if(path[i]==50)break;
            printf("%d->",path[i]);
        }
    printf("50\n");
    return 0;

}
