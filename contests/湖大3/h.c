// File Name: h.c
// Author: darkdream
// Created Time: 2013年07月18日 星期四 16时51分06秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
struct node
{
	int m,c;
}list[4005];
struct Hash
{
	int sit,num;
}hash[4005];
int ans[4005];
int nodecmp(const void *b ,const void * a)
{
	if( (*(node*)a).m != (*(node *)b).m)
		return (*(node *)a).m - (*(node *) b).m;
	else return (*(node*)a).c - (*(node *)b).c;
}
int intcmp(const void *a,const void *b)
{
	return *(int *)b -*(int *)a;
}
int hashcmp(const void *a ,const void *b)
{
	return (*(Hash *)b).num - (*(Hash *)a).num;
}
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n ,k ; 
	while(scanf("%d %d",&n,&k)!= EOF)
	{
		memset(list,0,sizeof(list));
		memset(hash,0,sizeof(hash));
		memset(ans,0,sizeof(ans));
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d %d",&list[i].m,&list[i].c);
		}


		qsort(list+1,n,sizeof(node),nodecmp);
		for(int i= 1;i <= n; i ++)
		{
			if(list[i].m != list[i-1].m)
			{
				hash[list[i].m].sit = i ; 
			}
			hash[list[i].m].num ++;
		}
		/* for(int i = 1;i <= n;i ++)
		   {
		   printf("****%d %d\n",list[i].m,list[i].c);
		   }*/

		qsort(hash+1,4000,sizeof(Hash),hashcmp);
		int up = 0 ;
		int ok = 1 ;
		/*for(int i= 1;i <= 7 ;i ++)
		  printf("%d ",hash[i].num);
		  printf("\n"); */

		if(hash[k].num == 0)
			ok = 0 ;

		if(ok)
		{
			int pre = 0 ;
			for(up = k; up <= 4000 ;  )
			{
				if(hash[up+1].num == hash[up].num)
				{
					up++;
				}
				else break;
			}
			  
			for(int i = 1; i <= up;i ++)
			{
				pre ++;
				ans[pre] = 0 ; 
				for(int j = hash[i].sit; j <= hash[i].sit + hash[k].num -1 ; j++)
				{
					ans[pre] += list[j].c;
				}
				//printf("????????%d\n",ans[pre]);
			}
			qsort(ans+1,pre,sizeof(int),intcmp);
			int sum = 0 ;
			for(int i= 1;i <= k ;i ++)
				sum += ans[i];
			printf("%d %d\n",hash[k].num,sum);

		}
		else 
			printf("0 0\n");
	}

	return 0 ;
}
