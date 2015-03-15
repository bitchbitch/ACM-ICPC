#include<cstdio>
#include<cstring>
char str[105];
int main()
{
	freopen("in","r",stdin);
	freopen("houzi","w",stdout);
	while(scanf("%s",str)!=EOF)
	{
		int flag = 1,tot = 0,len = strlen(str);
		for(int i = 0;i < len;++i)
		{
			if(str[i] == '(') tot++;
			else tot--;
			if(tot < 0) {flag = 0; break;}
		}
		tot = 0;
		for(int i = len - 1;i >= 0;--i)
		{
			if(str[i] == ')') tot++;
			else tot--;
			if(tot < 0) flag = 0;
		}
		printf(flag? "Yes\n":"No\n");
	}
	return 0;
}
