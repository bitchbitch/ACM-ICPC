#include<stdio.h>
int main(){
   int  n ; 
   while(~scanf("%d",&n))
   {
	  if(n%3)
		  printf("1\n");
	  else printf("0\n");
   }
   return 0 ; 
}
