/**
  *Problem 337A - Puzzles
  *ֱ�ӱ�����ʱ,����ע��dfs��ʱ��ǧ��Ҫ��ִ�й����ж��õ�����������,��tm��...�����ŷ�����������˽������
  *���ö�̬�滮....��tm dp.maxx=min(maxx,a[i+n]-a[i]);.....��ʵ�Ǹ�̰��+���򣬿����ˡ�����
  *�˵Ŀ۽Ű�T_T,�������Կ����¶�̬�滮��ô�⣬�϶�û���ַ����졣
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
