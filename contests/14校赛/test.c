// File Name: test.c
// Author: darkdream
// Created Time: 2014年05月11日 星期日 22时50分54秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   FILE *p1 = fopen("数颜色1.out","r");
   FILE *p2 = fopen("数颜色.out","r");
   char str1[20],str[20];
   int t  = 0 ; 
   while(fscanf(p1,"%s",str1) != EOF)
   {
       fscanf(p2,"%s",str);
		t ++ ; 
       if(strcmp(str,str1) != 0 )
		   printf("%d\n",t);
   }

return 0 ;
}
