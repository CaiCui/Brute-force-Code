#include <iostream>
#include<cstring>
using namespace std;
///���������� ˫��BFS����  ����˼·:״̬ö��+����
/** ����
 *
 * 1.�����ʼ��״̬��Ŀ��״̬
 * 2.bfs���������ر�
   3.ȡ����Ԫ�أ��ҵ�0��λ�ã�Ȼ���ĸ�����������������ĺ�0����λ�ã�����(��ϣ���أ�����������أ�STL��������)�����ļ��뵽��β�����½�����
   4.ֱ���ҵ�Ϊֹ������frontֵ
 * \return
 *
 */
#define maxn 10000
typedef int State[9];
State st[maxn];
State goal;
int dist[maxn];
///����ͻ�Ĺ�ϣ��������ұ���,��ϣֵ��ͬ�г�ͻ�ľ����ӳ�����û�еľ͵���һ������Ԫ��λ��
const int MAXHASHSIZE=1000003;///�Լ�ȡ
int head[MAXHASHSIZE],next[MAXHASHSIZE];///headԪ���±���ϣֵ��headֵ������next����ĵڼ���λ��(Ҳ�Ǹ�Ԫ���ڴ�����ԭ�����λ��,Ҳ�ǳ�ͻ���������Ԫ��)��
///next��������Ψһ��ϣֵ��nextֵ����0,�г�ͻ��nextԪ�أ�ÿһ��Ԫ�ض�����һ��������ǰһ����ͻ��Ԫ����ԭ����������λ��
void init_lookup_table()
{
    memset(head,0,sizeof(head));
}
int hashtest(State &s)
{
    int v=0;
    for(int i=0;i<9;i++)
        v=v*i+s[i];
    return v%MAXHASHSIZE;
}
int try_to_insert(int i)
{
    int h=hashtest(st[i]);
    int u=head[h];
    while(u)///�г�ͻ��,��Ϊû�г�ͻ��uһ����0
    {
        if(memcmp(st[u],st[i],sizeof(st[i]))==0)return 0;///ʧ�ܣ��ظ���
        ///���������
        u=next[u];
    }
    next[i]=head[h];
    head[h]=i;
    return 1; ///�ɹ�

}



int bfs()
{
    init_lookuptable();///��ʼ���ڵ����ر�
    int front,rear;
    front=1;
    rear=2;
    while(front<rear)
    {
        State &s=st[front];
        if(memcmp(goal,s,sizeof(s))==0)return front;
        int z;
        for(int i=0;i<9;i++)
            if(!s[i])break;
        int x=i/3;
        int y=i%3;
        for(int d=0;d<4;d++)
        {
            int newx=x+dx[d];
            int newy=y+dy[d];
            int newz=newx*3+newy;
            if(newx>=0&&newx<3&&newy>=0&&newy<3)
            {
                State &t=st[rear];
                memcpy(t,s,sizeof(s));
                t[newz]=s[z];
                t[z]=s[newz];
                dist[rear]=dist[front]+1;
                if(try_to_insert(rear))
                  rear++;///���뵽��չ�ڵ������

            }

        }
    }
}

int main()
{
   ///������ʼ״̬
   ///����Ŀ��״̬
   ///bfs();
    return 0;
}
