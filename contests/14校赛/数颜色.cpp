//Coded by 代码疯子
//http://www.programlife.net/
//POJ2777 SegMent Tree 线段树
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;

#define MAXNUM 100010
#define CLRNUM 32

typedef struct TagNode
{
	int left;
	int right;
	int cover;
}Node;

Node node[3*MAXNUM];
bool clr[CLRNUM];

void TreeMake(int x, int y, int idx)
{
	node[idx].left = x;
	node[idx].right = y;
	
	if(x == y)
	{
		return ;
	}
	int mid = (node[idx].left + node[idx].right) >> 1;
	TreeMake(x, mid, idx<<1);
	TreeMake(mid + 1, y, (idx<<1)+1);
}

void TreeUpdate(int x, int y, int col, int idx)
{
	if(x <= node[idx].left && y >= node[idx].right)
	{
		node[idx].cover = col;
		return ;
	}
	else
	{
		if(node[idx].cover >= 1)	//纯色
		{
			node[idx<<1].cover = node[idx].cover;		//纯色
			node[(idx<<1)+1].cover = node[idx].cover;	//纯色
			node[idx].cover = 0;	//混合颜色
		}
		int mid = (node[idx].left + node[idx].right) >> 1;
		
		if(x > mid)
		{
			TreeUpdate(x, y, col, (idx<<1)+1);
		}
		else if(y <= mid)
		{
			TreeUpdate(x, y, col, idx << 1);
		}
		else
		{
			TreeUpdate(x, mid, col, idx<<1);
			TreeUpdate(mid + 1, y, col, (idx<<1)+1);
		}
	}
}

void TreeQuery(int x, int y, int idx)
{
	if(node[idx].cover > 0)
	{
		clr[node[idx].cover] = 1;
	}
	else
	{
		int mid = (node[idx].left + node[idx].right) >> 1;
		if(x > mid)
		{
			TreeQuery(x, y, (idx<<1)+1);
		}
		else if(y <= mid)
		{
			TreeQuery(x, y, idx<<1);
		}
		else
		{
			TreeQuery(x, mid, idx<<1);
			TreeQuery(mid + 1, y, (idx<<1)+1);
		}
	}
}

int main()
{
	freopen("数颜色.in", "r", stdin);
	freopen("数颜色.out", "w", stdout);
	
	int l, t, n, i, j;
	char ch;
	int a, b, c, sum;
	int num;
	scanf("%d",&num);
	clock_t en,be;
	be = clock();
	while(num --)
	{
	    scanf("%d %d %d%*c", &l, &t, &n);
		TreeMake(1, l, 1);
		node[1].cover = 1;
		for(i = 1; i <= n; ++i)
		{
			scanf("%c", &ch);
			if(ch == 'C')
			{
				scanf("%d %d %d%*c", &a, &b, &c);
				TreeUpdate(a, b, c, 1);
			}
			else 
			{
				scanf("%d %d%*c", &a, &b);
				memset(clr, 0, sizeof(clr));
				TreeQuery(a, b, 1);
				sum = 0;
				for(j = 1; j <= t; ++j)
				{
					if(clr[j])++sum;
				}
				printf("%d\n", sum);
			}
		}
	}
	en = clock();
	//printf("%lf",(en -be)*1.0/CLOCKS_PER_SEC);

	return 0;
}
