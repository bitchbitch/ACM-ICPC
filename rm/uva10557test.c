#include <stdio.h>
int i,j,m,x,f,k,n,top,tail,q[100],visit[101],low[101],energy[101],map[101][101];
int main()
{
  while (scanf("%d",&n))
	{ 
	    if (n==-1) break;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				map[i][j]=0;
		for (i=1;i<=n;i++)
		{scanf("%d%d",&energy[i],&m);
			for (j=1;j<=m;j++)
			{scanf("%d",&x);
				map[i][x]=1;
			}
		}
		for (i=1;i<=n;i++)
		{visit[i]=1; low[i]=0;}
		visit[1]=0;  low[1]=100; q[0]=1;
		top=0;    tail=1;
		f=0;  m=0;
		while (top!=tail)
		{
		for (i=1;i<=n;i++)
			if ((map[q[top]][i]==1)&&(low[q[top]]+energy[i]>low[i]))
			{
				low[i]=low[q[top]]+energy[i];
				if (visit[i]==1)  
				{q[tail]=i;
					tail=(tail+1)%100;
					visit[i]=0;
					++m;
				}
			}
			visit[q[top]]=1;
			top=(top+1)%100;
			if (low[n]>0) {f=1;break;}
		}
		if (f==1) printf("winnable\n");
		else printf("hopeless\n");
	}
	return 0;
}
