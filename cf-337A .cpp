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
