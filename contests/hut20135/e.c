// File Name: e.c
// Author: darkdream
// Created Time: 2013年09月07日 星期六 13时34分01秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
struct node
{
	char str[1000];
	int y,num ; 
}cd[20005];
struct node1
{
	int be,en;
}seg[20005];
int cmp(const void * a ,const void * b)
{
	return (*(node*)a).y - (*(node *)b).y;
}
int main(){
	
	int t ;
	scanf("%d",&t);
	while(t--)
	{
	 int n;
	  scanf("%d",&n);
		for(int i =1 ;i <= n;i ++)
		{
		    scanf("%1s",cd[i].str);
            int len = strlen(cd[i].str) - 1;
			char c;
			while((c = getchar()) != '"')
			{
			   len ++;
			   cd[i].str[len] = c;
			}
		    cd[i].str[len+1] = '"';
			cd[i].str[len+2] = '\0';
			scanf("%d %d",&cd[i].y,&cd[i].num);
		}
		qsort(cd+1,n,sizeof(node),cmp);
		for(int i = 1;i <= n;i++)
			puts(cd[i].str);
		
	}
return 0 ;
}
