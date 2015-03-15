// File Name: uva10420.c
// Author: darkdream
// Created Time: 2013年02月24日 星期日 17时20分22秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct con{
  char name[100];
  int  t ;

};
int comp(const void*a,const void *b)
{
  return strcmp(((con*)a)->name,((con*)b)->name);
}
struct con  a[2020] ;
int main(){
    
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   memset(a,0,sizeof(a)); 
   int n , k = 0 ; 
   char temp1[100],temp2[100];
   scanf("%d",&n);
   getchar();
   while(n--)
   { int i ;
     scanf("%s",temp1);
	 gets(temp2);
	 for( i = 0;i < k ; i++ )
		 if(strcmp(temp1,a[i].name) == 0)
			 break;
	 if(k == 0 || i ==  k)
	 {
	    memcpy(a[k].name,temp1,sizeof(temp1));
		a[k].t = 1;
		k++;
		continue;
     }
	 else
	 {
	    a[i].t++;
   
	 }
   }
   qsort(a,k,sizeof(con),comp);
   for(int i = 0 ;i < k ;i++)
	   printf("%s %d\n",a[i].name,a[i].t);
   
return 0 ;
}
