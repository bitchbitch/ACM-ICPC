// File Name: uva644.c
// Author: darkdream
// Created Time: 2013年02月24日 星期日 14时41分07秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char a[20][1000] = {0};
int main(){
  int i = 1 , k = 1;
  while(scanf("%s",a[i]) != EOF)
  {
      if(strcmp(a[i],"9") == 0)
	  {  int p = 1;
		  for(int j = 1 ;j < i ;  j++)
			  for(int t = 1; t < i ;t++)
	          {
			      if(t == j) continue;
				  if(strstr(a[j],a[t]) && strstr(a[j],a[t]) - a[j] == 0)
				     p = 0;
			  }
		  if(p)
			  printf("Set %d is immediately decodable\n",k);
		  else
			  printf("Set %d is not immediately decodable\n",k);
         memset(a,0,sizeof(a));
		  k++;
		 i = 1;
	    continue; 
	  
	  }
	  i++;

  }
return 0 ;
}
