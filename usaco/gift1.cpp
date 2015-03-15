/*
ID: dream.y1
PROG: gift1
LANG: C++
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
	fscanf(fin,"%d\n",&n);
	memset(nodes,0,sizeof(nodes));
	for(int i = 1;i <= n;i ++)
	{
		fscanf(fin,"%s",nodes[i].str);
	}
	int a, b ;
	for(int i = 1;i <=n ;i ++)
	{
		char tstr[100];
		fscanf(fin,"%s",tstr);
		fscanf(fin,"%d %d\n",&a,&b);
		if(b == 0)
			continue;
		int k = a/b;
		for(int i = 1;i <=n; i ++)
			if(strcmp(tstr,nodes[i].str) == 0)
				nodes[i].num -= k*b;
		for(int i = 1;i <= b ;i ++)
		{
			fscanf(fin,"%s",tstr);
			for(int j = 1; j <=n ;j ++)
				if(strcmp(tstr,nodes[j].str) == 0)
				{
					nodes[j].num += k;                             
				}      
		}        

	}

	for(int i = 1;i <= n;i ++)
		fprintf(fout,"%s %d\n",nodes[i].str,nodes[i].num);

    free(fin);
	free(fout);
	return 0 ;



}
