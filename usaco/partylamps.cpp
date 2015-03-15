// File Name: partylamps.cpp
// Author: darkdream
// Created Time: 2013年11月29日 星期五 12时36分31秒
/*
ID: dream.y1
PROG: lamps
LANG: C++
*/
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

int minnum[100][6];
int op[5];
int sum = 0;
char ans[20][200];
int strcp(int a, int b)
{
  for(int i =1;i<= 105;i ++)
  {
    if(ans[a][i] > ans[b][i])
		return 0;
	else if(ans[a][i] < ans[b][i]) return 1;
  }
  return 0;
}
int main(){
	freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
	memset(minnum,0,sizeof(minnum));
	void dfs(int a ,int st);
	int k = 1; 
	for(int i = 1;i <= 3;i ++)
	{
		k  = (k << 1) +1;
	}
	op[1] = k;
	op[2] = (1 << 3) + (1 << 2);
	op[3] = (1 << 1) + 1;
	op[4] = (1 << 2) + (1 <<1);
	dfs(15,0);
	int n ,c;
	int ok1[5] = {0};
	int ok2[5] = {0};

	scanf("%d %d",&n,&c);
    
	for(;;)
	{
	  int temp;
	  scanf("%d",&temp);
	  if(temp == -1)
		  break;
	  if(temp % 2 == 0 )
	  {
	     if(temp % 3 == 1)
			 ok2[3] =1 ;
		 else ok2[4] =1;
	  }else{
	     if(temp % 3 == 1)
			 ok2[2] =1 ;
		 else ok2[1] =1;
	  } 
	}
    for(;;)
	{
	  int temp;
	  scanf("%d",&temp);
	  if(temp == -1)
		  break;
	  if(temp % 2 == 0 )
	  {
	     if(temp % 3 == 1)
			 ok1[3] =1 ;
		 else ok1[4] =1;
	  }else{
	     if(temp % 3 == 1)
			 ok1[2] =1 ;
		 else ok1[1] =1;
	  } 
	}
	
	for(int i =1; i <= 4; i ++)
	{
	    if(ok1[i] && ok2[i])
		{
			printf("IMPOSSIBLE\n");
		    return 0;
		}
	}
	
	  memset(ans,0,sizeof(ans));
	
	for(int i =0;i <= 15; i ++)
	{
	  int temp = i;
	  int ok[6] = {0};
	  for(int j = 1;j <= 4;j ++)
	  {
			  ok[j] = temp % 2;
			  temp /= 2;
	  }
	  int is = 1;
	  for(int j =1; j<= 4;j ++)
	  {
	     if(ok[j] && ok1[j])
			 is = 0 ;
         if(!ok[j] && ok2[j])
			 is = 0 ;
	  }


	  if(is)
	   {  
		   for(int j = 0;j <= 4 ;j ++ )
		   {
		       if(minnum[i][j] && c >= j && (c- j)% 2 == 0)
			   {
			     sum ++;
				 for(int s = 1 ;s <= n; s ++)
				 {
				      if(s % 2 == 0 )
					  {
					    if(s % 3 == 1)
						{
						   if(ok[3])
							   ans[sum][s] = '1';
						   else ans[sum][s] = '0';
						}else{
							if(ok[4])
								ans[sum][s] = '1';
							else ans[sum][s] = '0';
						} 
					  }else {
					    if(s % 3 == 1){
							if(ok[2])
								ans[sum][s] = '1';
							else ans[sum][s] = '0';
						
						}else {
						    if(ok[1])
								ans[sum][s] = '1';
							else ans[sum][s] = '0';
						}
					     
					  
					  }
				 }
//				 printf("%s\n",&ans[sum][1]);
//				 printf("%d\n",sum);
				 break;
			   }
		   }
	   }
	}
  //  printf("%d\n",sum);
	for(int i =1; i <= sum; i++)
		for(int j =i+1; j <= sum ;j ++)
		{
		   if(!strcp(i,j))
		   {
	//		printf("%s\n",&ans[i][1]);
		     char strtemp[200];
			 memcpy(strtemp,ans[i],sizeof(char)*200);
			 memcpy(ans[i],ans[j],sizeof(char)*200);
			 memcpy(ans[j],strtemp,sizeof(char)*200);
		   }
		}
	for(int i= 1;i<= sum ;i ++)
		printf("%s\n",&ans[i][1]);
	if(sum == 0 )
		printf("IMPOSSIBLE\n");


	return 0;
}


void dfs(int a,int st)
{
	//printf("%d\n",a);
	minnum[a][st] = 1;
	if(st == 4)
		return;
	for(int i =1 ;i <= 4;i ++)
	{
		dfs(a^op[i],st+1);
	}
}
