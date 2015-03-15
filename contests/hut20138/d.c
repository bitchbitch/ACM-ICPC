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
#pragma comment(linker,"/STACK:102400000,102400000")

using namespace std ;

long long pos[100];
long long num[30];
long long dp[20][40000]; 
long long row , zt , limits[30] ,n; 
long long su[30];
void dfs(long long  pop,long long status)
{
	if(pop == su[row+1] )
	{
		dp[row+1][status] +=  dp[row][zt];
		return ;
	}

	if(row+1 <= n){

		if(pop % 2 == 0 ){	  
			if(pop + 1 < su[row+1] && num[pop] == 0 ) 
			{   
				dfs(pop+2,status);
				dfs(pop+1,status+pos[pop/2]);
			}
			else 
				dfs(pop+1,status+pos[pop/2]);
		}
		else {
			if(num[pop-1])
				dfs(pop+1,status);
			else {
				dfs(pop+2,status);
			}
		}

	}
	else {
		if(pop % 2 == 1 ){
			if(row == n?num[pop+1] == 0: num[pop+2] ==  0)
			{   
				if(pop + 2 == su[row+1])
					dfs(pop+2,status);
				else{
					dfs(pop+2,status);
					dfs(pop+1,status + pos[pop/2]);
				}
			}
			else
				dfs(pop+1,status+pos[pop/2]);
		}
		else {
			if(row == n ? num[pop]:num[pop+1])
				dfs(pop+1,status);
			else {
				if(pop + 1 < su[row+1])
					dfs(pop+2,status);
			}

		}	

	}

}
void change(long long k)
{
	memset(num,0,sizeof(num));
	long long m = k ; 
	long long t = -2 ; 
	while(m)
	{
		t = t+2; 
		num[t] = m%2;
		m = m/2;
	}

} 
void change1(long long k)
{
	memset(num,0,sizeof(num));
	long long m = k ; 
	long long t = -1 ; 
	while(m)
	{
		t = t+2; 
		num[t] = m%2;
		m = m/2;
	}
} 
int main()	
{
	pos[0] = 1;
	for(long long i = 1;i <= 18; i ++ )
	{
		pos[i] = 2* pos[i-1];	
	}

	memset(limits,0,sizeof(limits));
	int t  = 0;
	while(scanf("%lld",&n)!=EOF)
	{
		t ++;
		for(long long i = 1;i <= n;i ++)
			limits[i] = n+i;
		for(long long i = n+1 ;i <= 2*n ;i ++)
			limits[i] =  limits[2*n -i+1] -1;
		for(long long i = 1;i <= n;i ++)
			su[i] = 2*(n+i) - 1; 
		for(long long i = n+1; i <= 2*n ;i ++)
			su[i] =  su[2*n-i+1];



		memset(dp,0,sizeof(dp));
		dp[0][0] = 1; 
		for(row = 0 ; row < 2*n ; row ++)
			for(zt = 0 ; zt < pos[limits[row]+1]; zt ++)
			{
				if(dp[row][zt])
				{
					if(row <= n) 
						change(zt);
					else 
						change1(zt);
					dfs(0,0); 
				}
			}
		if(t!= 1 )
			printf("\n");

		printf("%lld\n",dp[2*n][0]);
	}
	return 0 ; 

}
