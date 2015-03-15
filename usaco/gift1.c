/*
ID: dream.y1
LANG: C
PROG: gift1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
	char str[100];
	int num;       
}nodes[100];
int main()
{
	FILE *fin = fopen("gift1.in","r");
	FILE *fout  = fopen("gift1.out","w");	
	int n; 
	scanf("%d",&n);
	getchar();
	memset(nodes,0,sizeof(nodes));
	for(int i = 1;i <= n;i ++)
	{
		gets(nodes[i].str);
	}
	int a, b ;
	while(1)
	{
		char tstr[100];
		gets(tstr);
		fscanf(fin,"%d %d",&a,&b);
		getchar();
		if(a == 0 && b == 0 )
			break;
		printf("%d %d\n",a,b);
		int k = a/b;
		for(int i = 1;i <=n; i ++)
			if(strcmp(tstr,nodes[i].str) == 0)
				nodes[i].num -= k*b;
		for(int i = 1;i <= b ;i ++)
		{
			gets(tstr);
			for(int j = 1; j <=n ;j ++)
				if(strcmp(tstr,nodes[j].str) == 0)
				{
					nodes[j].num += k;                             
				}      
		}        

	}

	for(int i = 1;i <= n;i ++)
		fprintf(fout,"%s %d\n",nodes[i].str,nodes[i].num);


	return 0 ;



}

