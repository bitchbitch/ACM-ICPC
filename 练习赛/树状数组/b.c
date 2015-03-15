// File Name: b.c
// Author: darkdream
// Created Time: 2013年03月22日 星期五 10时24分42秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

char a[100005];
char b[100005];
char c[200010];
char d[200010];
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   while(scanf("%s",a) != EOF && scanf("%s",b)!=EOF )
   {
	  char *p = a;
	  int ok = 0;
	  memset(c,0,sizeof(c));
	  memset(d,0,sizeof(d));
	  for(int i = 0 ;i < strlen(a) -1 ;i ++)
	  {
		 p = p +i;
		 if(strstr(b,p) && strstr(b,p)-b == 0)
		 {
			 ok = 1;
			 break;
		 }
      }
	  if(ok)
	  { memcpy(c,a,sizeof(char)*(p-a));
	    memcpy(c+(p-a),b,sizeof(b));
	  }
	  else
	  { 
	    memcpy(c,a,sizeof(char)*strlen(a));
		memcpy(c + strlen(a),b,sizeof(b));
	  }
	  p = b;
	  ok = 0 ;
	  for(int i = 0 ;i < strlen(b) -1 ;i ++)
	  {
		 p = p +i;
		 if(strstr(a,p) && strstr(a,p)-a == 0)
		 {
			 ok = 1;
			 break;
		 }
      }
	  if(ok)
	  { memcpy(d,b,sizeof(char)*(p-b));
	    memcpy(d+(p-b),a,sizeof(a));
	  }
	  else
	  { 
	    memcpy(d,b,sizeof(char)*strlen(b));
		memcpy(d + strlen(b),a,sizeof(a));
	  }
	  if(strlen(c) > strlen(d) )
		  puts(d);
	  else if(strlen(c) < strlen(d))
		  puts(c);
	  else
	  {
	     if(strcmp(c,d)>=0)
			 puts(d);
		 else
			 puts(c);
	  }

   }
return 0 ;
}
