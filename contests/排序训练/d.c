// File Name: d.c
// Author: darkdream
// Created Time: 2014年03月05日 星期三 20时01分01秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node{
	char name[39];
	int num; 
	int time;
}a[300];
int cmp(const void *a ,const void *b)
{
	if((*(node*)a).num == (*(node *)b).num)
	{
		if((*(node*)a).time == (*(node *)b).time)
			return strcmp((*(node *)a).name,(*(node *)b).name);
		return (*(node *)a).time - (*(node *)b).time;
	}
	return (*(node *)b).num - (*(node *)a).num;
}
int main(){
	int n, m ;
	scanf("%d %d",&n,&m);
	int t = 0 ; 
	while(scanf("%s",a[++t].name)!= EOF)
	{
		for(int i =1 ;i <= n; i ++)
		{
			int temp ;
			scanf("%d",&temp);
			//	printf("\n***(%d)***\n",temp);

			if(temp > 0)
			{
				a[t].num ++;
				a[t].time += temp ;
				char c = getchar();
				if(c == '(')
				{
					int k ; 
					scanf("%d",&k);
				//	printf("\n***(%d)***\n",k);
					a[t].time += k * m ;		
					getchar();
				}
			}	
		}
		
	}
	qsort(a+1,t-1,sizeof(node),cmp);
	for(int i = 1;i <= t-1;i ++)
	{
		printf("%-10s %2d %4d\n",a[i].name,a[i].num,a[i].time);
	}

	return 0 ;
}
