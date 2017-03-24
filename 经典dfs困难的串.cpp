#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
///困难的串
#define maxn 100
int S[maxn];
int L,n;
int dfs(int cur)
{
    if(cur==n)
    {
        for(int i=0;i<cur;i++)
            printf("%c",'A'+S[i]);
        printf("\n");
        return 1;
    }
    for(int i=0;i<L;i++)
    {
        S[cur]=i;
        int ok=1;
        for(int j=1;j*2<=cur+1;j++)
        {
            int equal=1;
            for(int k=0;k<j;k++)
            if(S[cur-k]!=S[cur-k-j]){equal=0;break;}
            if(equal){ok=0;break;}
        }

        if(ok)
           {
           if(dfs(cur+1))
            return 1;
           }

    }
    return 0;
}
int main()
{
    cin>>n>>L;
    if(!dfs(0))
    cout<<"无解"<<endl;


  return 0;
}
