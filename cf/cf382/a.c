// File Name: a.c
// Author: darkdream
// Created Time: 2014年01月17日 星期五 23时31分06秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[10000];
char str1[100];
int main(){
  scanf("%s",str);
  int k = 0 ; 
  for(int i = 0 ; i  < strlen(str); i ++)
	  if(str[i] == '|')
      {
	    k =  i ;
		break;
	  }
  int ka = k ;
  int kb = strlen(str) - ka - 1;
  scanf("%s",str1);
  int len = strlen(str1); 
  //printf("%d %d %d\n",ka,kb,len);
  if(len >= abs(ka - kb) && (len- abs(ka - kb))%2 == 0) 
  {
    for(int i = 0;i < k ;i ++ )
		printf("%c",str[i]);
	if(ka >= kb)
	{
	   for(int i = 0 ;i < (len-abs(ka-kb))/2 ; i ++)
		   printf("%c",str1[i]);
	   for(int i = k;i < strlen(str) ;i ++)
		   printf("%c",str[i]);
	   for(int i = (len - abs(ka-kb))/2; i < len ;i ++)
		   printf("%c",str1[i]);
		    
	}else{
	   for(int i = (len - abs(ka-kb))/2; i < len ;i ++)
		   printf("%c",str1[i]);
	   for(int i = k;i <strlen(str) ;i ++)
		   printf("%c",str[i]);
	   for(int i = 0 ;i < (len-abs(ka-kb))/2 ; i ++)
		   printf("%c",str1[i]);
	
	}
  }else printf("Impossible\n");
return 0 ;
}
