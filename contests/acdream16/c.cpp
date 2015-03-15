#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;
#define di  3
int dp[11][60000];
int n,m,row;
int num[20],pp[20];
int visit[15][15];
void dfs(int  pos ,int  st,int a)
{
	if(pos > n )
	{
		if(dp[row][st] == -1)
			dp[row][st] = a;
		else{
			dp[row][st] = min(dp[row][st],a);
		}
	    return ;
	}
	if(pos == 1){
		if(num[pos] == 1)
		{
			dfs(pos+1,st+2*pp[pos],a);
		}else if(num[pos] == 2){
			if(visit[row][pos] == 0)
				dfs(pos+1,st+pp[pos],a+1);
			dfs(pos+1,st,a);
		}else {
			if(visit[row][pos] == 1)
				return;
			else dfs(pos+1,st+pp[pos],a+1);
		}
		return ;
	}
	int t = st/pp[pos-1];
	if(t == 1){  
		if(num[pos] == 0 )
			return;
		else  
			dfs(pos+1,st + 2*pp[pos],a);
	}else if(t == 2){
		if(num[pos] == 1){
			dfs(pos+1,st+2*pp[pos],a);
		}else if(num[pos] == 2){
			if(visit[row][pos] == 0)
			{
				dfs(pos+1,st+pp[pos],a+1);
			}
			dfs(pos+1,st,a);
		}else {
			if(visit[row][pos] == 0)
			{
				dfs(pos+1,st+pp[pos],a+1);
			}else{
				return ;
			}
		}
	}else {
		if(num[pos] == 1){  
			dfs(pos+1,st+ 2*pp[pos],a);
		}else if(num[pos] == 2){  
			if(visit[row][pos] == 0)
			{
				dfs(pos+1,st+pp[pos]+2*pp[pos-1],a+1);
			}
			dfs(pos+1,st,a);
		}else {
			if(visit[row][pos] == 0)
			{
				dfs(pos+1,st+pp[pos]+2*pp[pos-1],a+1);
			}else{
				return ;
			}
		}
	}

}
void change(int zt)
{
	int now = zt;
	int  k = 0 ; 
	memset(num,0,sizeof(num));
	if(now == 0 )
		return ; 
	while(now){
		num[++k] = now % di;
		now/= di;
	}
}
int ok(int zt)
{
    for(int k = n; k >= 1 ; k -- )
	 {
	     if(zt/pp[k] == 0 )
			 return  0 ; 
		 zt = zt % pp[k]; 
	 }
	return 1;
}
int main(){
	pp[0] = 1;
	pp[1] = 1; 
	for(int i = 2;i <= 10 ;i ++) pp[i] = pp[i-1]*di;
	while(scanf("%d %d",&n,&m) != EOF)
	{

		memset(visit,0,sizeof(visit));
		memset(num,0,sizeof(num));
		for(int i =1;i <= m; i ++)
		{
			int a,b; 
			scanf("%d %d",&a,&b);
			visit[a][b] = 1; 
		}
		memset(dp,-1,sizeof(dp));
		
		int temp = 0 ;
		for(int i =1; i <= n;i ++)
			temp += 2* pp[i];
		dp[0][temp] = 0 ;

		for(row = 1 ;row <= n;row ++)
		{
			for(int i = 0;i <= pp[n+1]; i ++)
			{
				if(dp[row-1][i] != -1)
				{
					change(i);
					dfs(1,0,dp[row-1][i]);
				}
			}
	//		printf("*****\n");
		}
		int ans = 1000 ;
		for(int i = 0 ;i <= pp[n+1]; i ++)
		{
		   if(dp[n][i] != -1)
		   {
		     if(dp[n][i] < ans && ok(i))
			 {
				  ans = min(dp[n][i],ans);
			 }
		   }
		}
        if(ans == 1000)
			printf("-1\n");
		else 
		    printf("%d\n",ans);
	} 
	return 0;
}
