// File Name: uva123.c
// Author: darkdream
// Created Time: 2013年03月05日 星期二 15时18分48秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char key[55][300] = {0};
int k , t , n = 0 ;
struct nokey
{
	char c[300];
	int site[205];
	int sited[205];
	int  s;
};
struct title
{
	char old[4505];
	char word[20][300];
	int  w;

};
struct nokey nokeys[3005] = {0} ;
struct title titles[205] = {0} ;

int find(char a[], int s,int h)
{
	for (int i = 1; i <= k ; i++)
	{
		if (strcmp(a,key[i]) == 0) 
			return 0;
	}
	for (int i = 1; i<= n ; i ++)
	{
		if(strcmp(a,nokeys[i].c) == 0)
		{  
			nokeys[i].s++;
			nokeys[i].site[nokeys[i].s] = s;
			nokeys[i].sited[nokeys[i].s] = h ;
			return 0;
		}

	}
	for (int i = 1; i <= k ; i++)
	{
		if (strcmp(a,key[i]) == 0) 
			return 0;
	}
	memcpy(nokeys[n+1].c,a,sizeof(titles[s].word[h]));
//	puts(nokeys[n+1].c);
	nokeys[n+1].s  = 1;

	nokeys[n+1].site[1] = s;
	nokeys[n+1].sited[1] = h;
	return 1;

}
int  savekey()
{
	int i = 1;
	char temp[20];
	while(scanf("%s",temp))
	{
		if(strcmp(temp,"::") == 0)
			return i-1;
		memcpy(key[i],temp,sizeof(temp));
		i++;
	}

}

int savetitle()
{
	char a[400];
	int i = 1; 
	while(gets(a))
	{
		for (int j = 0 ; j < strlen(a); j++)
			a[j] = tolower(a[j]);
		memcpy(titles[i].old,a,sizeof(a));
		int h = 1;
		char *p = a ;
		while(sscanf(p,"%s",titles[i].word[h]) != EOF)
		{
			if(find(titles[i].word[h],i,h))
			{
				n = n+1;
			}
			h = h +1;
			p = strstr(p,titles[i].word[h-1]) + strlen(titles[i].word[h-1]);
		}
		titles[i].w = h -1 ;
		i++;
	}
	return i -2;

}

void print()
{
	for(int i = 1; i <= n; i ++)
		for(int j = i+1;j <=  n ;j ++)
			if(strcmp(nokeys[i].c,nokeys[j].c) >= 0)
			{
				struct nokey temp = nokeys[i];
				nokeys[i] = nokeys[j];
				nokeys[j] = temp;
			}
//	for(int i = 1 ; i <= n; i ++)
//		printf("%s %d\n",nokeys[i].c,strlen(nokeys[i].c));
	for(int i = 1;i <= n; i ++)
	{  int j = 1;
		for (j = 1; j <= nokeys[i].s; j ++)
		{  int l  =	0 , r = 0 ;
			for (  ;r < strlen(titles[nokeys[i].site[j]].old); r++)
			{
				if(isalpha(titles[nokeys[i].site[j]].old[r]))
				{
					if( r == 0  || titles[nokeys[i].site[j]].old[r-1] == ' ')
					{   l++;
						if(l == nokeys[i].sited[j])
						{  
							for (int q = 0; q < strlen(titles[nokeys[i].site[j]].word[l]); q++)
								printf("%c",toupper(titles[nokeys[i].site[j]].word[l][q]));
							r = r + strlen(titles[nokeys[i].site[j]].word[l]) - 1   ;
						}
						else
						{
							printf("%s",titles[nokeys[i].site[j]].word[l]);		
							r = r + strlen(titles[nokeys[i].site[j]].word[l]) - 1  ;
						}
					}
				}
			   else printf("%c",titles[nokeys[i].site[j]].old[r]);

			}
			printf(" ");
			printf("\n");
		}
	}

}

int main(){


   // freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	memset(key,0,sizeof(key));
	memset(titles,0,sizeof(titles));
	memset(nokeys,0,sizeof(nokeys));
	k = savekey();
	t = savetitle();
	print();
	return 0 ;
}
