#include <stdio.h>
#define N 1001
#define C(n,m) c[(n)+1][(m)+1]
#define MOD 1000000007
int c[N][N];
int main()
{
    int n;
    scanf("%d",&n);
    c[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
    int ans=0;
    for(int i=2;i<=n-2;i++)
        ans=(ans+(long long)C(n-1,i)*((i-1)*(n-i-1))%MOD)%MOD;
    printf("%d\n",ans);
    return 0;
}
