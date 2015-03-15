#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define maxn 10
char mapp[maxn][maxn];
int visited[maxn][maxn];
int n,m,t;
int flag,sum;

void DFS(int x,int y)
{
    if(flag || x <= 0 || y <= 0 || x > n || y > m || mapp[x][y] == 'X' || visited[x][y])
    {
        return;
    }
    sum++;
    if(mapp[x][y] == 'D' && sum == t)
    {
        flag=1;
        return;
    }
    visited[x][y] = 1;
    DFS(x + 1,y);
    DFS(x - 1,y);
    DFS(x,y + 1);
    DFS(x,y - 1);
    sum--;
    visited[x][y]=0;
}

int main()
{
    int x,y,x1,y1;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        if(n == 0 && m == 0 && t == 0)
        {
            break;
        }
        getchar();
        memset(visited,0,sizeof(visited));
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                scanf("%c",&mapp[i][j]);
                if(mapp[i][j] == 'S')
                {
                    x = i;
                    y = j;
                }
                else if(mapp[i][j] == 'D')
                {
                    x1 = i;
                    y1 = j;
                }
            }
            getchar();
        }
        if((t-(abs(x-x1)+abs(y-y1)))%2!=0)
        {
            printf("NO\n");
            continue;
        }
        flag = 0;
        sum = -1;
        DFS(x,y);
        if(flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
