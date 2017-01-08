
///�������� ������������ ID�㷨
/**--
��������������ʵ�������޶��½������������������������������������K�㣬��û�з��ֿ��н⣬�ٽ�K+1��
�ظ����ϲ���������ֱ�����������н⡣
�ڵ��������������㷨�У�����������������������룬ÿһ�����Լ����μ�1��ֱ��������Ŀ��Ϊֹ����������
�����ظ������˺öࡣ�������ĺô����ڣ�
1.�ռ俪��С   ÿ�������ʵ������һ���������������������������ƣ���DFS�Ŀռ�����С��������֪�ġ�
2.������ȼ�֦
3.ʱ��Ч�ʲ��� ��Ȼ�ظ����������Ǵ�Ҳ�����⣬ǰһ����������һ���಻��΢���㵽�ġ�
���ǿ��Կ������������������㷨���Ƿ¹�������������������������������������������������Դ洢Ҫ��
���ܱ�֤����һ����С��ȵ�Ŀ���㡣
��ʵ��Ӧ����������������������Ч���ȽϺã������ȹ�������������ܶ࣬���ǿռ临�Ӷ�ȴ���������������ͬ��
�ȹ����������С�ܶࡣ
ʹ�������㷨��ʱ��ѡ����ȷ��������ʽ����Ҫ������һ��������Ҫ���������������
��ȴû���㹻�Ŀռ䣬��ʱ��ȴ�ܳ�ԣ�������������⣬���ǿ���ѡ��������������㷨��
�ص�:��������BFS�����޿�ȵĹ��,ͬʱ��DFS����������ȵ�����
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
const int MAXN = 30; //��������������Ϊ30���㹻����
long long int test[MAXN]; //���ÿ�������ķ�ĸ
long long int best[MAXN]; //�����ñ��ʽ�ķ�ĸ
int parts = 0; //��ǰ���������
int found = 0; //�ҵ���ñ��ʽ
long long int gcd(long long int a, long long int b) //շת�����������Լ��
{
    if(!b)
    {
        return a;
    }
    return gcd(b, a%b);
}
void IteratorDeep(long long int m, long long int n, int deep) /*m/n��deep�������*/
//��deep����µ�������ʵ������ģ���deep���ѵ���1�㣬����ѭ������for(i=deep; i>0; --i),������һ����
{
    long long int t = gcd(n, m);
    m /= t;
    n /= t;
    if(1 == deep) //���������1ʱ
    {
        if(1 == m) //�����ҵ�����Ҫ��ķֽ�
        {
            test[0] = n;
            if(!found || (found && best[0] > n)) //����ȵ�ǰ�����Ž⻹Ҫ�ã��滻��,��С����Խ��Խ�õ�����������best[0] > n
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
        long long int min = n / m + 1;///���ӷ������ֵ�����Ͻ� ������ĸö�ٵ���Сֵ//��ǰ�ֽ�ʣ��Ľ��Ϊm/n����(1/(n/m))<ע:���������ȡ������>,��n%m=0,��Ȼm/n���Ա�ʾ��1/k,����deep!=1,����Ҫ�����ֽ⣬��min=n/m+1
                                       //��n%m!=0,��ôn/m����ȡ��,��Ϊk,��1/k>n/m,������Ҫ�󣬹�min=n/m+1
        if(deep < parts && min < test[deep] + 1) ///��֦ ��֤�����ظ�ö��ǰ����ֹ��ķ�ĸ,ͬʱҲ������ö���� //��ǰ��Ȳ���parts(��һ�εݹ�����),������Ĭ�ϵķ�ĸ�ǵ�����
                         //���� 19/45=1/5 + 1/6 + 1/18.  ǰһ��ķ�ĸ���Ⱥ�һ��С</span>
        {
            min = test[deep] + 1;
        }
        long long int max = (deep*n%m == 0) ? (deep*n/m-1) : (deep*n/m); ///���ӷ����ڵ�ǰ�ɷֽ�ĸ����ڵ���Сֵ ���½磬��ö�ٷ�ĸ�����ֵ //ÿһ�����ֽ��һ���ӷ���������ʣ��deep��(��ס����������)������ԣ����ֽ��deep���ӷ����������ڷ�ĸ����ԭ�����Ա����ĸ���Ϊdeep*n/m���Ƿ��ȥ1��ȡ�����غ�ȡminʱ��ͬ
        for(long long int i=min; i<=max; ++i) //����С��ĸ������ĸ֮�������һ�ݹ飬ֱ���ҵ�
        {
            test[deep-1] = i;
            IteratorDeep(m*i-n, n*i, deep-1); /// (m/n)-(1/i) = (m*i-n)/(n*i),ʣ��ķ���������һ��
        }
    }
}
int main()
{
    long long int a, b; //�����ʵ����ֱ����int�ͣ�Ϊ�˱�������鷳���ٺ�
    while(cin >> a >> b)
    {
        memset(test, 0, sizeof(test)); //��ʼ״̬
        memset(best, 0, sizeof(best));
        cout << a << "/" << b << "=";
        long long int t = gcd(b, a); //������ӷ�ĸ�����Լ����Ȼ�󻯼�
        a /= t;
        b /= t;
        if(1 == a) //ֱ�ӻ����1/n��ʽ������Ҫ��
        {
            cout << 1 << "/" << b << endl;
            continue;
        }
        parts = 1; //��ǰ���Ϊ1
        found = 0;
        while(!found) //���δ�ҵ���һֱ����ȥ
        {
            ++ parts; //ÿ����ȼ���
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
