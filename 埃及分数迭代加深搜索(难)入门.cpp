
///埃及分数 迭代加深搜索 ID算法
/**--
迭代加深搜索，实质上是限定下界的深度优先搜索。即首先允许深度优先搜索K层，若没有发现可行解，再将K+1后
重复以上步骤搜索，直到搜索到可行解。
在迭代加深搜索的算法中，连续的深度优先搜索被引入，每一个深度约束逐次加1，直到搜索到目标为止。这样可以
看出重复搜索了好多。但是它的好处在于：
1.空间开销小   每个深度下实际上是一个深度优先搜索，不过深度有限制，而DFS的空间消耗小是众所周知的。
2.利于深度剪枝
3.时间效率不低 虽然重复搜索，但是大家不难理解，前一次搜索跟后一次相不是微不足到的。
我们可以看出，迭代加深搜索算法就是仿广度优先搜索的深度优先搜索。既能满足深度优先搜索的线性存储要求，
又能保证发现一个最小深度的目标结点。
从实际应用来看，迭代加深搜索的效果比较好，并不比广度优先搜索慢很多，但是空间复杂度却与深度优先搜索相同，
比广度优先搜索小很多。
使用搜索算法的时候，选择正确的搜索方式很重要。当有一类问题需要做广度优先搜索，
但却没有足够的空间，而时间却很充裕，碰到这类问题，我们可以选择迭代加深搜索算法。
特点:适用于用BFS有无限宽度的广度,同时用DFS又有无限深度的问题
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
const int INF = ~0U>>1;
const int N = 10;
int dep,flag;
int ans[N],d[N];
int gcd(int a,int b)
{
    return b ? gcd(b,a%b):a;
}
void dfs(int a,int b,int k)
{
    if(k == dep + 1) return;
    if(b % a == 0 && b / a > d[k-1])
    {
        d[k] = b / a;
        if(!flag || d[k] < ans[k])
             memcpy(ans,d,sizeof(d));
        flag = 1;
        return;
    }
    int s = b / a;
    if(s <= d[k-1]) s = d[k-1] + 1;
    int t = (dep - k + 1) *  b / a;
    if(t > INF / b) t = INF / b;
    if(flag && t >= ans[dep]) t = ans[dep] - 1;
    for(int i=s;i<=t;i++)
    {
        d[k] = i;
        int m = gcd(i*a - b,b*i);
        dfs((i*a-b)/m,b*i/m,k+1);
    }
}

void Work(int a,int b)
{
    d[0] = 1;
    flag = 0;
    for(dep=1;dep <= N;dep++)
    {
        dfs(a,b,1);
        if(flag)
        {
            printf("1/%d",ans[1]);
            for(int i=2;i<=dep;i++)
                printf("+1/%d",ans[i]);
            cout<<endl;
            break;
        }
    }
}

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<a<<"/"<<b<<"=";
        Work(a,b);
    }
    return 0;
}
**/
#include <iostream>
#include<cstring>
using namespace std;
const int MAXN = 30; //定义最大搜索深度为30，足够大了
long long int test[MAXN]; //存放每次搜索的分母
long long int best[MAXN]; //存放最好表达式的分母
int parts = 0; //当前搜索的深度
int found = 0; //找到最好表达式
long long int gcd(long long int a, long long int b) //辗转相除法求出最大公约数
{
    if(!b)
    {
        return a;
    }
    return gcd(b, a%b);
}
void IteratorDeep(long long int m, long long int n, int deep) /*m/n的deep深度搜索*/
//在deep深度下的搜索其实是逆向的，从deep层搜到第1层，就像循环函数for(i=deep; i>0; --i),道理是一样的
{
    long long int t = gcd(n, m);
    m /= t;
    n /= t;
    if(1 == deep) //搜索到深度1时
    {
        if(1 == m) //终于找到符合要求的分解
        {
            test[0] = n;
            if(!found || (found && best[0] > n)) //如果比当前的最优解还要好，替换它,最小分数越大越好的限制条件，best[0] > n
            {
                found = 1;
                for(int i=parts-1; i>=0; --i)
                {
                    best[i] = test[i];
                }
            }
        }
    }
    else
    {
        long long int min = n / m + 1;///求子分数最大值，即上界 ，即分母枚举的最小值//当前分解剩余的结果为m/n，即(1/(n/m))<注:这儿不！是取整操作>,若n%m=0,虽然m/n可以表示成1/k,但是deep!=1,所以要继续分解，则min=n/m+1
                                       //若n%m!=0,那么n/m属于取整,令为k,则1/k>n/m,不符合要求，故min=n/m+1
        if(deep < parts && min < test[deep] + 1) ///剪枝 保证不会重复枚举前面出现过的分母,同时也减少了枚举量 //当前深度不是parts(第一次递归的深度),而我们默认的分母是递增的
                         //例如 19/45=1/5 + 1/6 + 1/18.  前一项的分母都比后一项小</span>
        {
            min = test[deep] + 1;
        }
        long long int max = (deep*n%m == 0) ? (deep*n/m-1) : (deep*n/m); ///求子分数在当前可分解的个数内的最小值 即下界，即枚举分母的最大值 //每一层最多分解出一个子分数，所以剩余deep层(记住：逆向搜索)如果可以，最多分解出deep个子分数，又由于分母递增原则，所以本层分母最大为deep*n/m，是否减去1，取决因素和取min时相同
        for(long long int i=min; i<=max; ++i) //对最小分母和最大分母之间进行逐一递归，直到找到
        {
            test[deep-1] = i;
            IteratorDeep(m*i-n, n*i, deep-1); /// (m/n)-(1/i) = (m*i-n)/(n*i),剩余的分数进入下一层
        }
    }
}
int main()
{
    long long int a, b; //这儿其实可以直接用int型，为了避免调试麻烦，嘿嘿
    while(cin >> a >> b)
    {
        memset(test, 0, sizeof(test)); //初始状态
        memset(best, 0, sizeof(best));
        cout << a << "/" << b << "=";
        long long int t = gcd(b, a); //求出分子分母的最大公约数，然后化简
        a /= t;
        b /= t;
        if(1 == a) //直接化简成1/n形式，符合要求
        {
            cout << 1 << "/" << b << endl;
            continue;
        }
        parts = 1; //当前深度为1
        found = 0;
        while(!found) //如果未找到则一直找下去
        {
            ++ parts; //每次深度加深
            IteratorDeep(a, b, parts);
        }
        for(int i=parts-1; i>0; --i)
        {
            cout << 1 << "/" << best[i] << "+";
        }
        cout << 1 << "/" << best[0] << endl;
        cout<<parts;
    }
    return 0;
}
