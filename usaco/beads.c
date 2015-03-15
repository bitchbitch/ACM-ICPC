/*
ID: dream.y1
PROG: beads
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
char str[1000];
int max = 0;
int n; 
void dosomthing(int t)
{
    int suma = 0 , sumb =0 ;
	char tempa = t - 1 == -1? str[n-1] :str[t-1];
	for(int i  = t -1 ;; i--)
	{
      if(i == -1)
		  i = n -1; 
	  if(i == t )
		  break;
      if(str[i] == 'w' || tempa == str[i] || tempa == 'w')
	  { 
		 if(tempa == 'w' && str[i] != 'w')
			 tempa = str[i];
		 suma ++;
	  }

	  else break;
	}
	
    tempa = str[t];
	int k = t-1 == -1?n-1:t-1;
	for(int i  = t ;; i++)
	{
      if(i == n)
		  i = 0; 
	  if(i == k)
		  break;
      if(str[i] == 'w' || tempa == str[i] || tempa == 'w')
	  {
		 if(tempa == 'w' && str[i] != 'w')
			 tempa = str[i];
		  sumb ++;
	  }
	  else break;
	}
  //fprintf(fout,"%d %d %d\n",suma,sumb,suma + sumb);
   if(suma + sumb > n)
   {
	   max = n;
   }
   else  if(suma + sumb > max)
	   max = suma + sumb;

    
}
int main(){
   FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   fscanf(fin,"%d",&n);
   fscanf(fin,"%s",str);
 for(int i = 0;i < n;i ++)
   {
         dosomthing(i);
   }
   fprintf(fout,"%d\n",max);
return 0 ;
}
