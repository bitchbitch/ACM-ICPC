/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2015-03-20 10:33
 * Filename : j.1.cpp
 * Description :
 * *********************************************************/
/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2015-03-20 10:15
 * Filename : j.1.cpp
 * Description :
 * *********************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
const int maxm = 62;
const int mod = 1000000007;

int m,n;
char str[maxn];
int nxt[maxn][maxm],a[maxn];
ll dp2[maxn],p[maxn];
int dp1[maxn];

int change(char ch){
    if(ch>='a'&&ch<='z')return ch-'a';
    if(ch>='A'&&ch<='Z')return ch-'A'+26;
    return ch-'0'+52;
}

void pd(ll&ret,ll val){
    ret+=val;
    if(ret>=mod)ret-=mod;
}

void init(){
    scanf("%d%s",&m,str);
    n=strlen(str);
    for(int i=0;i<n;i++)a[i+1]=change(str[i]);
    for(int i=0;i<m;i++)nxt[n][i]=-1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++)nxt[i][j]=nxt[i+1][j];
        nxt[i][a[i+1]]=i+1;
		for(int j = 0 ;j < m;j ++)
			printf("%d ",nxt[i][j]);
	printf("\n");
    }
    p[0]=1;
    for(int i=1;i<maxn;i++)p[i]=p[i-1]*m%mod;
}

int main() {
//    freopen("ACM/generated.in", "r", stdin);
  //  freopen("ACM/out.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        for(int i=n;i>=0;i--){
            bool sign=0;
            dp1[i]=dp2[i]=0;
            for(int j=0;j<m;j++)
                if(nxt[i][j]==-1){
                    sign=1;
                    break;
                }
            if(sign){
                dp1[i]=1;
                for(int j=0;j<m;j++){
                    if(nxt[i][j]==-1)continue;
                    dp2[i]++;
                }
            }else{
                int mi=n+5;
                for(int j=0;j<m;j++){
                    int tt=nxt[i][j];
                    mi=min(mi,dp1[tt]);
                }
                dp1[i]=mi+1;
                //if(i==2)printf("** %d\n",mi);
                for(int j=0;j<m;j++){
                    int tt=nxt[i][j];
                   // if(i==2)printf("** %d\n",dp1[tt]);
                    if(dp1[tt]==mi)pd(dp2[i],dp2[tt]);
                    else pd(dp2[i],p[mi]);
					if(i == 1)
						printf("%d %d***%lld\n",j,tt,dp2[i]);
                }
            }
        }
		for(int i = n ;i >= 0 ;i --)
			printf("%3lld",dp2[i]);
		printf("\n");
		for(int i = n ;i >= 0 ;i --)
			printf("%3d",dp1[i]);
		printf("\n");
     //   for(int i=0;i<=n;i++)printf("%d: %d %lld\n",i,dp1[i],dp2[i]);
        printf("%d %lld %lld\n",dp1[0],(p[dp1[0]]+mod-dp2[0])%mod,dp2[0]);
    }
    return 0;
}
