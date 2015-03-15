/*
ID: dream.y1
PROG: namenum
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
FILE *fin = fopen("namenum.in","r");
FILE *fout = fopen("namenum.out","w");
FILE *fin1 = fopen("dict.txt","r");
int high,n;
char  map[5005][100];
char str[100];
char c[200];
int ok =0 ;
void dfs(char temp ,int step)
{

	void find();
   int t = temp - '0'- 2 ;
   for(int i = t*3+1; i <= (t+1)*3;i ++)
   {
		   str[step] = i - 1 + 'A';
		   if(i > 16)
			 str[step] += 1;
		   if(step < n -1)
		    dfs(c[step+1],step+1);
		   else
		   {
		      str[n] = '\0';
			  find();
		   }
   }
   return ;
}
void find()
{
  //fprintf(fout,"%s\n",str);
  int low = 1; 
  int up = high;
  while(low <= up)
  {
    int mid = (low + up)/2;
	if(strcmp(str,map[mid]) < 0)
		up = mid - 1;
	else if(strcmp(str,map[mid]) > 0)
		low = mid + 1;
	else{
		fprintf(fout,"%s\n",str);
		 ok = 1;
	  return ;
	}
  }
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   high = 1 ;
   while(fscanf(fin1,"%s",map[high]) != EOF)
   {
     high ++;
   }
   high --;
   fscanf(fin,"%s",c);
   n = strlen(c);
   dfs(c[0],0);
   if(ok == 0 )
	   fprintf(fout,"NONE\n");
return 0 ;
}
