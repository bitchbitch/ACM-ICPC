#include<stdio.h>
#include<stdlib.h>
struct load
{
	int a;
	int b;
	int c;
}lo[10000];
int city[100];
int h[100];
int Comp(const void *p1,const void *p2)
{
	return ((*(load*)p1).c > (*(load*)p2).c)?1:-1;
}
int main()
{
	int n,m;
	int i,j;
	int sum;
	int find(int x);
	void uni(int x,int y);
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&lo[i].a);
			scanf("%d",&lo[i].b);
			scanf("%d",&lo[i].c);
		}
		for(i=0;i<m;i++)
		{h[i]=i;}
		qsort(lo,n,sizeof(lo[0]),Comp);
		for(i=0,j=0;i<m&&j<n;i++)
		{
			while(find(lo[j].a)==find(lo[j].b))
			{j++;}
			uni(lo[j].a,lo[j].b);
			j++;	
		}
		if(sum==m)
		{printf("%d\n",sum);}
		else
		printf("?\n");
	}
	return 0;
}
int find(int x)
{
	return (h[x]==x)?x:(h[x]=find(h[x]));
}
void uni(int x,int y)
{
	h[find(x)]=find(y);
}
