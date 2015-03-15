#include <cstdio>
#include <cstring>
#define maxn 120

char s[maxn]; 
int A[maxn],B[maxn];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(A, 0, sizeof A);
		memset(B,0, sizeof B);
		scanf("%s",s+1);
		int L= strlen(s+1);
		A[0]= L;
		for(int i= L,j=1; i>= 1; i--,j++)
			A[j]= s[i]-'0';
		scanf("%s",s+1);
		L= strlen(s+1);
		B[0]= L;	 
		for(int i= L,j=1; i>= 1; i--,j++)
			B[j]= s[i]-'0';
		int sum= A[0]> B[0]? A[0]: B[0];
		int ans= 0;
		for(int i= 1; i<= sum; i++)
			if(A[i]+B[i]> 9)
			{
				A[i+1]++;
				ans++;
			}
		printf("%d\n",ans);	
	}
	return 0;
}
