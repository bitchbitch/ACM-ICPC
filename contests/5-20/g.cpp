// File Name: g.cpp
// Author: darkdream
// Created Time: 2013年05月20日 星期一 18时39分26秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

int a[100][100];
int temp[100][100];
int b[100];
int cmp(const int i, const int j)
{
    return b[i] > b[j];
}

int main(){

	int n  , m;
	while(scanf("%d %d",&n,&m) != EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(temp,0,sizeof(temp));
		for(int i = 1; i<= n;i ++ )
		{
			for(int j = 1; j <= m; j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j] == 0)
					b[j]++;
			}


		}
		int r[100];
		for(int i = 1;i <= m;i ++)
		{
		   r[i] = i ;
		}
		sort(r+1,r+m+1,cmp);
		int j = 1;
		for(int i = 1;;i++ )
		{
		  for(int t = 1; t <= n;t ++)
		  {
			  temp[t][i] = a[t][r[j]];
		  }
		  j = j+2;
		  if(j > m)
			  break;
		}
		j = 2;
		for(int i = m;;i-- )
		{
		  for(int t = 1; t <= n;t ++)
		  {
			  temp[t][i] = a[t][r[j]];
		  }
		  j = j+2;
		  if(j > m)
			  break;
		}


		int sum  = 0 ;
		for(int i = 1; i <= n;i ++)
		  for(int j = 1; j <= m;j ++)
		  {
		     if(temp[i][j] == 0)
			 {
			   int ok1 = 0 , ok2 = 0 ;
			   for(int t = 1 ; t < j ;t ++)
				   if(temp[i][t] == 1)
					   ok1  = 1;
			   for(int t = j+1; t <= m;t ++)
			       if(temp[i][t] == 1)
					   ok2 = 1;
			   if(ok2 && ok1)
				   sum++;
			 }
		  }
		/*for(int i = 1;i <= n;i ++)
		{
		  for(int j =1 ;j <= m; j++)
			  printf("%d ",temp[i][j]);
		  printf("\n");
		}*/
    printf("%d\n",sum);
		
	}
	return 0 ;
}

