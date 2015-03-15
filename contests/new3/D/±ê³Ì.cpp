#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 3333

struct node
{
	char ch[1111];
	int num;
}a[maxn];

bool cmp(node x, node y)
{
	return x.num> y.num;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, t= 0;
	while(scanf("%d",&n)!=EOF)
	{ 
		for(int i= 1; i<= n; i++)
			scanf("%s %d",a[i].ch,&a[i].num);
		sort(a+1, a+n+1, cmp);
		printf("Case #%d:\n",++t);	
		for(int i= 1; i<= n; i++)
			printf("%s\n",a[i].ch);
	}
	return 0;

}
