#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAXN 500005
int n, k ;
int a[MAXN];
struct node
{
	int left ,right ,mid ;
	int num ;
}tree[MAXN * 4];
int L(int c)
{
	return 2 * c;
}
int R(int c)
{
	return 2 * c + 1;
}
void build(int c, int p , int v)
{
	tree[c].left = p ;
	tree[c].right = v;
	tree[c].mid = (p+v)/2;
	tree[c].num = (v-p+1);
	if(p == v )
	{
		return;
	}
	build(L(c),p,tree[c].mid);
	build(R(c),tree[c].mid + 1, v);
}
int tsum = 0  ;
void getsum(int c, int p ,int v )
{
	if(p <= tree[c].left && v >= tree[c].right)
	{
		tsum += tree[c].num;
		return;
	}
	if(v <= tree[c].mid) getsum(L(c),p,v);
	else if(p > tree[c].mid ) getsum (R(c),p,v);
	else
	{
		getsum(L(c),p,tree[c].mid);
		getsum(R(c),tree[c].mid+1, v );
	}
}
int ok =0 ;
void update(int c, int p)
{   tree[c].num -- ;
	if(tree[c].left == tree[c].right)
	{
		ok = tree[c].left;
		return;
	}
	if(tree[L(c)].num >= p ) update(L(c),p);
	else update(R(c),p - tree[L(c)].num);
}
char str[MAXN][13];
int RPrime[]={//反素数
	1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,
	20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,
	554400
};

int fact[]={//反素数约数个数
	1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,
	144,160,168,180,192,200,216
};

int main()
{

	while(scanf("%d %d",&n,&k) != EOF)
	{
		int P = 0 ;
		for(int i= 0; RPrime[i]<= n;i++)P=i; 

		for(int i = 1;i <= n;i ++)
		{
			scanf("%s %d",str[i],&a[i]);
		}
		build(1,1,n);
		update(1,k);
		int temp = a[k];
		int temps = k ;
		int ansi =0 ;
		int t = 1 ;
		while(tree[1].num != 0)
		{
			t ++ ;
			if(temp > 0 )
			{
				tsum = 0 ;
				getsum(1,1,temps);
				if(tsum >= temp)
				{
					update(1,tsum-temp + 1);
				}
				else
				{
					update(1,tree[1].num - (temp - tsum) + 1 );
				}
			}
			else
			{
				tsum = 0 ;
				getsum(1,temps,n);
				temp = -temp;
				if(tsum >= temp)
				{
					update(1,tree[1].num - (tsum - temp));
				}
				else
				{
					update(1,temp - tsum);
				}
			}
			temps = ok;
			temp = a[ok];
		//	printf("%d\n",ok);
			// printf("%d\n",ok);
			if(t >= RPrime[P])
		    	break;

		}
		printf("%s %d\n",str[t],fact[P]);
	}
	return 0 ;
}
