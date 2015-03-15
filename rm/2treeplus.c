// File Name: 2treeplus.c
// Author: darkdream
// Created Time: 2013年03月21日 星期四 16时43分34秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void build (int n , char *s1,char *s2 , char *s)
{
   if (n <= 0) return; 
   int p = strchr(s2,s1[0]) - s2;
   build(p,s1+1,s2,s);
   build(n-p-1,s1+p+1,s2+p+1,s+p);
   s[n-1] = s1[0];
}

int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    char s1[100],s2[100],ans[100];

    while(scanf("%s %s",s1,s2) != EOF)
	{
	  int n = strlen(s1);
	  build(n,s1,s2,ans);
      ans[n] = '\0';
	  printf("%s\n",ans);
	}
return 0 ;
}
