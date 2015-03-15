/*
ID: dream.y1
PROG: friday
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main(){

	 FILE *fin  = fopen ("friday.in", "r");
	 FILE *fout = fopen ("friday.out", "w");
	int a[13] = {31,31,29,31,30,31,30,31,31,30,31,30};
	int b[13] = {31,31,28,31,30,31,30,31,31,30,31,30};
	int time[8] = {0} ;
	int n; 
	fscanf(fin,"%d",&n);
	int t = 5;
	for(int i = 1900 ;i  <= 1900 + n -1;i ++ )
	{
		if((i % 100 == 0 && i % 400 == 0 ) || (i % 100 != 0  && i % 4 == 0 ))
		{
			for(int j = 1; j <= 12 ;j ++)
			{
					t = (t + a[j-1]) %7;
					time[t] ++;
			}

		}
		else
		{
			for(int j = 1;j <= 12 ;j ++)
			{
					t = (t + b[j-1]) %7;
					time[t] ++;
			}
		}
		
	}
	for(int i= 1;i <= 6;i ++)
		fprintf(fout,"%d ",time[i]);
	fprintf(fout,"%d\n",time[0]);

	return 0 ;
}
