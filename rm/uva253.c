// File Name: uva253.c
// Author: darkdream
// Created Time: 2013年02月04日 星期一 13时19分45秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct mian
{
   char  a , b ;
   bool t ; 
};
struct mian s[4];
struct mian t[4];
void find()
{
   int i ,j;
   for(i = 1; i <= 3 ; i++)
    for (j = 1; j <= 3; j++)
	{
	   if(((t[i].a == s[j].b && t[i].b == s[j].a)||(t[i].a == s[j].a && t[i].b== s[j].b))&&s[j].t == 1)
	     {
			 s[j].t = 0;
			 break;
		 
		 }
	}
}
int main(){
	char a[20];
	while(gets(a))
	{
	memset(s,0,sizeof(s));
	memset(t,0,sizeof(t));
    int i ;
	for (i = 1; i<= 3; i ++)
		s[i].t = 1;
	s[1].a = a[0];
	s[1].b = a[5];
	s[2].a = a[1];
	s[2].b = a[4];
	s[3].a = a[2];
	s[3].b = a[3];
	t[1].a = a[6];
	t[1].b = a[11];
	t[2].a = a[7];
	t[2].b = a[10];
	t[3].a = a[8];
	t[3].b = a[9];
   find();
   if (!s[1].t && !s[2].t && !s[3].t)
	   printf("TRUE\n");
   else
	   printf("FALSE\n");

	}
return 0 ;
}
