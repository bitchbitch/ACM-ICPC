#include <cstdio>
#include <cstring>

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char ch[111];
	while(scanf("%s",ch+1)!=EOF)
	{
		int L= strlen(ch+1);
		int t= 0;
		for(int i= 1; i<= L; i++)
		{
			t= t*10+ (ch[i]- '0');
			t= t%17;
		}
		if(t)
			printf("NO\n");
		else
			printf("YES\n");	
	}
	return 0;
}
