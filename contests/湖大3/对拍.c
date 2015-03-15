#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

int rec[300000],cnt;

struct Node
{
	int x,y;
	Node(){};
	Node(int xx,int yy)
	{
		x=xx;
		y=yy;
	}
	bool friend operator<(Node a,Node b)
	{
		return a.y>b.y;
	}
};

priority_queue<Node> que;

int main()
{
	int i,n;
	int g,cnt,sum;
	char s[4];
	//freopen("/home/plac/problem/input.txt","r",stdin);

	while(~scanf("%d",&n))
	{
		while(!que.empty()) que.pop();
		for(i=2;i<=n;i++)
		{
			scanf("%s%d",s,&g);
			if(s[0]=='d')
			{
				que.push(Node(i,g));
			} 
			else if(n!=i)
			{
				while(que.size()>=g)
				{
					que.pop();
				}
			}
		}
		if(que.size()<g)
		{
			printf("-1\n");
			continue;
		}
		cnt=0;
		sum=0;
		while(!que.empty())
		{
			sum+=que.top().y;
			rec[cnt++]=que.top().x;
			que.pop();
		}
		sort(rec,rec+cnt);
		printf("%d\n",sum);
		printf("%d\n",cnt);
		for(i=0;i<cnt-1;i++)
		{
			printf("%d ",rec[i]);
		} 
		printf("%d\n",rec[cnt-1]);
	}
	return 0;
}
