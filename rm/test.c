#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
struct node
{

     int next,to;

};
node g[10010];
int head[110];
int d[110];
int visit[110];
int cnt[110];
int f[110][110];
int s[110];
int n,num;
int ff;
void add(int from,int to)
{

     g[num].to=to;
     g[num].next=head[from];
     head[from]=num++;
}
void dfs(int from,int fa,int &ff)
{

     int i,to;
     visit[from]=1;
     if(from==fa)
     {

          ff=1;
          return;
     }
     for(i=head[from];i!=-1;i=g[i].next)
     {

            to=g[i].to;
            if(!visit[to])
            {

                  dfs(to,fa,ff);
                  if(ff)
                  return;
            }
     }
}
void spfa()
{

     int i,from,to;
     int j,k;
     int flag=0;
     queue<int>q;
     memset(d,0,sizeof(d));
     memset(cnt,0,sizeof(cnt));
     memset(visit,0,sizeof(visit));
     cnt[1]=1;
     d[1]=100;
     q.push(1);
     for(;!q.empty()&&!flag;)
     {

           from=q.front();
           q.pop();
           visit[from]=0;
           for(i=head[from];i!=-1;i=g[i].next)
           {

                    to=g[i].to;
                    //printf("%d %d %d %d %d\n",from,to,s[to],d[from],d[to]);
                    if(d[to]<d[from]+s[to])
                    {

                         d[to]=d[from]+s[to];
                         if(!visit[to])
                         {

                              visit[to]=1;
                              cnt[to]++;
                              if(cnt[to]>n)
                              {

                                   flag=1;
                                   break;
                              }
                              q.push(to);
                         }
                    }
           }
     }
     if(d[n]>0)
     {

          printf("winnable\n");
          return;
     }
     else
     {
         for(i=1;i<=n;i++)
         {

            if(cnt[i]>n)
            {
                int f1=0;
                int f2=0;
                memset(visit,0,sizeof(visit));
                dfs(1,i,f1);
                dfs(i,n,f2);
                if(f1&&f2)
                {
                  printf("winnable\n");
                  return;
                }
            }
         }
     }
     printf("hopeless\n");
}
void solve()
{

     int i,j,m;
     int x,y;
     num=0;
     memset(head,-1,sizeof(head));
     memset(f,0,sizeof(f));
     for(i=1;i<=n;i++)
     {

           scanf("%d %d",&s[i],&m);
           for(j=0;j<m;j++)
           {

                scanf("%d",&y);
                f[i][y]=1;
                add(i,y);
           }
     }
     spfa();
}
int main()
{

      for(;scanf("%d",&n)&&n!=-1;)
      {

            solve();
      }
      return 1;
}
