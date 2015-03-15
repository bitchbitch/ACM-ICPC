// File Name: uva572.c
// Author: darkdream
// Created Time: 2013年05月22日 星期三 19时19分08秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[128][128];
int visit[128][128];
int mivisit[120][120];
struct node 
{
	int i , j ;

}nodes[10000],minodes[1000];
int cmp(const void *a,const void *b)
{
	return *(int *)a - *(int*)b;
}
int xadd[] = {+1,-1,0,0};
int yadd[] = {0,0,+1,-1};
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n ,m,t =  0; 
	while(scanf("%d %d",&n,&m) != EOF)
	{
		t ++;
		memset(str,0,sizeof(str));
		memset(nodes,0,sizeof(nodes));
		memset(visit,0,sizeof(visit));
		memset(mivisit,0,sizeof(mivisit));
		if(n == 0 && m == 0)
			break;
		for(int i = 1;i <= m; i ++)
		{
			scanf("%s",&str[i][1]);
		}
		int sum = 0 ;
		int k[1000];
		for(int i = 1 ; i <= m ;i ++)
		{
			for(int j = 1 ;j <= n ; j++)
			{
				if((str[i][j] == '*' || str[i][j] == 'X' )&& visit[i][j] == 0)
				{
					memset(nodes,0,sizeof(nodes));
					sum++;
					nodes[1].i = i ; 
					nodes[1].j = j ;
					visit[i][j] =1 ;
					int low  = 1, high = 1,temp =  0;;
					while(low <= high )
					{
						for(int k = 0 ;k < 4 ;k ++)
						{  
							int tx = nodes[low].i + xadd[k];
							int ty = nodes[low].j + yadd[k];
							if((str[tx][ty] == '*' ||str[tx][ty] == 'X') && !visit[tx][ty] )
							{
								if(str[tx][ty] == 'X' && !mivisit[tx][ty] )
								{
									temp ++;
									memset(minodes,0,sizeof(minodes));
									minodes[1].i = tx;
									minodes[1].j = ty;
									mivisit[tx][ty] = 1 ;
									int milow = 1, mihigh = 1; 
									while(milow <= mihigh )
									{
										for(int s = 0 ;s < 4 ;s ++)
										{  
											int mitx = minodes[milow].i + xadd[s];
											int mity = minodes[milow].j + yadd[s];
											if( str[mitx][mity] == 'X' && !mivisit[mitx][mity] )
											{
												mihigh++;
												mivisit[mitx][mity] = 1; 
												minodes[mihigh].i = mitx;
												minodes[mihigh].j = mity;
											}
										}
										milow++;
									}

                                }
								high++;
								visit[tx][ty] = 1; 
								nodes[high].i = tx;
								nodes[high].j = ty;
							}
						}
						low++;
					}
					k[sum] = temp;
				}
			}
		}
		printf("Throw %d\n",t);
	    qsort(k+1,sum,sizeof(int),cmp);
		for(int i = 1;i <= sum ;i ++)
		{
			if(i != 1)
			   printf(" ");
			printf("%d",k[i]);
		}
		printf("\n\n");

	}
	return 0 ;
}

