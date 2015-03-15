/*
ID: dream.y1
PROG: transform
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

char str[100][100];
char change[100][100];
char temp[100][100];
int n;
int change1(char s[][100])
{
	for(int i = 1;i<= n;i ++)
		for(int j = 1; j <= n;j ++)
		{
		  if(s[i][j] != change[j][n-i+1])
			  return 0;
		}
	return 1;
}
int change2(char s[][100])
{
	for(int i = 1;i<= n;i ++)
		for(int j = 1; j <= n;j ++)
		{
		  if(s[i][j] != change[n-i+1][n-j+1])
			  return 0;
		}
	return 1 ;

}
int change3(char s[][100])
{
	for(int i = 1;i<= n;i ++)
		for(int j = 1; j <= n;j ++)
		{
		  if(s[i][j] != change[j][n-i+1])
			  return 0;
		}
	return 1 ;


}
int change4(char s[][100])
{
   for(int i = 1;i<= n;i ++)
	   for(int j= 1;j <= n;j ++)
	   {
	      if(s[i][j] != change[i][n-j+1])
			  return 0 ;
	   }
   return 1;
}
int change5(char s[][100])
{
    for(int i = 1;i<= n;i ++)
		for(int j = 1;j<= n;j ++)
		{
		  temp[i][j] = s[i][n-j+1];
		}
	if(change1(temp))
		return 1;
	if(change2(temp))
		return 1;
	if(change3(temp))
		return 1;
	return 0 ;
}
int change6( char s[][100])
{
  for(int i =1 ;i <= n;i ++)
	  for(int j =1 ;j <= n;j ++)
	  {
	    if(s[i][j] != change[i][j])
			return 0;
	  }
  return 1;
}
int main(){
   FILE *fin = fopen("transform.in","r");
   FILE *fout = fopen("transform.out","w");
   //freopen("/home/plac/fproblem/input.txt","r",stdin);
   //freopen("/home/plac/fproblem/output.txt","w",stdout);
   fscanf(fin,"%d",&n);
   memset(str,0,sizeof(str));
   memset(change,0,sizeof(change));
   for(int i = 1; i <= n;i ++)
	   fscanf(fin,"%s",&str[i][1]);
   for(int i =1 ;i<= n; i ++ )
	   fscanf(fin,"%s",&change[i][1]);
   if(change1(str))
	   fprintf(fout,"1\n");
   else if(change2(str))
	   fprintf(fout,"2\n");
   else if(change3(str))
	   fprintf(fout,"3\n");
   else if(change4(str))
	   fprintf(fout,"4\n");
   else if(change5(str))
	   fprintf(fout,"5\n");
   else if(change6(str))
	   fprintf(fout,"6\n");
   else fprintf(fout,"7\n");


return 0 ;
}
