#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
#include <iomanip>
#include<iostream>
#include<algorithm>
using namespace std ;
char s[50000];

int work()
{
	int len = strlen(s),k=0;
    char a[20005];
	memset(a,0,sizeof(a));
	for(int i = 0 ; i < len/2 ; i++)
	{
		if(s[i]!=s[(len-1)-i])
			k++;
		a[i] = s[i] ;   
	}
	strcpy(s,a);
	return k;
}

int main()
{
	clock_t  be,en;
	be = clock();
	freopen("DNA.in","r",stdin);
	freopen("DNA1.out","w",stdout);
	int  t,len ;
	scanf("%d",&t);
	while(t--)
	{
	//	memset(s,0,sizeof(s));
		scanf("%d %s",&len,s);	
		int cnt=0,ans=0,k=strlen(s);
		while(k!=len)
		{
			k /= 2 ;
			cnt++;
			ans += work();
		}
		printf("%d %d\n",cnt,ans);    

	} 
	en = clock();
	printf("%lf\n",(en-be)*1.0/CLOCKS_PER_SEC);
	return 0;
} 
