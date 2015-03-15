/*
ID: dream.y1
PROG: calfflac
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char str[30005] = {0};
char temp[30005] = {0};
int change[30005],t;
int max = 0 ;
int begin,end;
void dosome(int n )
{
	int q = n ;
	int h = n + 1;
	for(;q >= 0, h < t ;q --, h ++  )
	{
		if(temp[q] != temp[h])
		{
			break;
		}
	}
	if(h - q - 1 > max)
	{
		begin = q+1;
		end = h-1; 
		max = h-q-1;
	}
	q = n-1 ; 
	h = n+1;
	for(;q >= 0, h < t ;q --, h ++  )
	{
		if(temp[q] != temp[h])
		{
			break;
		}
	}
	if(h - q - 1 > max)
	{
		begin = q+1;
		end = h-1; 
		max = h-q-1;
	}
}
int main(){
    FILE *fin = fopen("calfflac.in","r");
	FILE *fout = fopen("calfflac.out","w");
	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int s = 0 ;
    char ch;
	while((ch = fgetc(fin)) != EOF )
	{
	  str[s] = ch;
	  s ++;
	}
	int lenstr = s;
	for(int i= 0 ;i < lenstr; i++)
	{
		if(isalpha(str[i]))
		{
			temp[t] = tolower(str[i]);
			change[t] = i; 
			t ++;
		}
	}
	for(int i = 0 ;i < t; i ++)
	{
		dosome(i);
	}
	if(max == 3)
		fprintf(fout,"%s",temp);
	fprintf(fout,"%d\n",max);
	for(int i = change[begin]; i <= change[end]; i ++)
		fprintf(fout,"%c",str[i]);
	fprintf(fout,"\n");

	return 0 ;
}
