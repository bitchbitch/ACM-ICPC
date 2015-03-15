#include <stdio.h>
#include <string.h>
#define maxn 200011

struct node
{
	int l, r,m;
	int max;
}a[4*maxn+5];
int b[maxn];
int Max(int x,  int y)
{
    if(x > y )
		return x ; 
	else return y ; 
}

void Build(int l, int r, int n)
{
	a[n].l= l;
	a[n].r= r;
	a[n].max= 0;
	if(l == r)
	{
		a[n].max = b[l];
		return ; 
	}
	a[n].m= (l + r)/ 2;
	Build(l, a[n].m, 2*n);
	Build(a[n].m+1, r, 2*n+1);
	a[n].max = Max(a[n*2].max,a[n*2+1].max);
}

void Add(int v, int num, int n)
{
	if(v == a[n].l && v == a[n].r)
	{
		a[n].max = num;
		return;
	}
	if(v <= a[n].m)
		Add(v, num, 2*n);
	else
		Add(v, num, 2*n+1);
	a[n].max= Max(a[2*n].max, a[2*n+1].max);				
}
int max = -1;
void Qmax(int l, int r, int n)
{
	if(a[n].l <= l && a[n].r >= r)
	{	 
		max = Max(max,a[n].max);
	     return ;
	}
	if(r<= a[n].m)
	   Qmax(l, r, 2*n);
	else if(l> a[n].m)
	   Qmax(l, r, 2*n+1);
	else{
	   Qmax(l, a[n].m, 2*n);
	   Qmax(a[n].m+1, r, 2*n+1);
	}
}

int main()
{
	int n, m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i= 1; i<= n; i++)
		{
			scanf("%d",&b[i]);
		}
		Build(1, n, 1);
		char ch;
		int v, num;
		while(m--)
		{
		    max = -1;
			
			scanf("%c %d %d",&ch,&v, &num);
			if(ch=='Q')
			 {
				Qmax(v, num, 1);
			    printf("%d\n",max); 
			 }
			else if(ch == 'U')
			{
				Add(v, num, 1);	
			}
		}
	}
	return 0;
}
