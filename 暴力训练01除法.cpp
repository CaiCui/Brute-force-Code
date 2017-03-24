//Ñ­»·¼ôÖ¦
#include <iostream>
#include<cstring>
using namespace std;
int test[10];
int main()
{

   int n,x,y,j,tag,i,yy,tag2;
   while(cin>>n)
   {
     tag=0;
     tag2=0;
   for(int a=0;a<10;a++)
    for(int b=0;b<10;b++)
      for(int c=0;c<10;c++)
       for(int d=0;d<10;d++)
        for(int e=0;e<10;e++)
   {
       x=a*10000+b*1000+c*100+d*10+e;
      if(a==b||a==c||a==d||a==e||b==c||b==d||b==e||c==d||c==e||d==e)
        continue;
       y=x*n;
       if(y/10000>10)
        continue;
        if(x/1000>0&&x/10000==0)
            tag2=1;
       yy=y;
       test[a]=-1;
       test[b]=-1;
       test[c]=-1;
       test[d]=-1;
       test[e]=-1;
       for( i=0;i<5;i++)
       {
           int m;
           m=y%10;
           y=y/10;
           for(j=0;j<10;j++)
            {
                if(test[j]==m)
                {
                    test[j]=-1;
                    break;
                }
            }
            if(j==10)
                break;

       }
       if(i==5&&!tag2)
       {
           cout<<yy<<"/"<<x<<"="<<n<<endl;
           tag=1;
       }
       if(i==5&&tag2)
       {
           cout<<yy<<"/0"<<x<<"="<<n<<endl;
           tag=1;
           tag2=0;
       }

       for(int i=0;i<10;i++)
         test[i]=i;
   }
   if(!tag)
     cout<<"ÎŞ½â"<<endl;
   }
   return 0;
}
