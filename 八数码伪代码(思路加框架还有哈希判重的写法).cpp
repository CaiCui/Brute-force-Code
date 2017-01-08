#include <iostream>
#include<cstring>
using namespace std;
///八数码问题 双向BFS搜索  整体思路:状态枚举+判重
/** 流程
 *
 * 1.输入初始化状态和目标状态
 * 2.bfs构造结点判重表
   3.取队首元素，找到0的位置，然后四个方向搜索，不出界的和0交换位置，判重(哈希判重，编码解码判重，STL集合判重)后合理的加入到队尾，更新结点距离
   4.直到找到为止，返回front值
 * \return
 *
 */
#define maxn 10000
typedef int State[9];
State st[maxn];
State goal;
int dist[maxn];
///带冲突的哈希函数与查找表建立,哈希值相同有冲突的就链接成链表，没有的就单开一个数组元素位置
const int MAXHASHSIZE=1000003;///自己取
int head[MAXHASHSIZE],next[MAXHASHSIZE];///head元素下标存哈希值，head值存属于next链表的第几个位置(也是该元素在待检测的原数组的位置,也是冲突链表的最新元素)，
///next是链表，有唯一哈希值的next值都是0,有冲突的next元素，每一个元素都存着一条链表，存前一个冲突的元素在原待检测数组的位置
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
    while(u)///有冲突了,因为没有冲突则u一定是0
    {
        if(memcmp(st[u],st[i],sizeof(st[i]))==0)return 0;///失败，重复了
        ///否则继续找
        u=next[u];
    }
    next[i]=head[h];
    head[h]=i;
    return 1; ///成功

}



int bfs()
{
    init_lookuptable();///初始化节点判重表
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
                  rear++;///加入到扩展节点队列中

            }

        }
    }
}

int main()
{
   ///输入起始状态
   ///输入目标状态
   ///bfs();
    return 0;
}
