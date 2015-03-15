// File Name: f.c
// Author: darkdream
// Created Time: 2014年03月05日 星期三 20时36分01秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int n, t; 
struct hehe{
   char sgname[100];
   char dqname[100];
   int num;
}b[101];
int cmp(const void *a ,const void *b)
{
    if(strcmp((*(hehe *)a).dqname,(*(hehe*)b).dqname) == 0)
       return   strcmp((*(hehe *)a).sgname,(*(hehe*)b).sgname);
     return   strcmp((*(hehe *)a).dqname,(*(hehe*)b).dqname);
}
int main(){
   int t ; 
   scanf("%d",&t);
   while(t--)
   {
	 scanf("%d",&n);
	 for(int i = 1;i <= n;i ++)
	 {
	   scanf("%s %s %d",b[i].sgname,b[i].dqname,&b[i].num);
	 }
	 qsort(b+1,n,sizeof(hehe),cmp);
	 int num  = 0 ; 
	 for(int i = 1;i <= n;i ++)
	 {
	   if(i == 1 )
	   {
		   printf("%s\n   |----%s(",b[i].dqname,b[i].sgname);
		   num = b[i].num;
		   continue;
	   }
	   if(strcmp(b[i].dqname,b[i-1].dqname) != 0 )
	   {
		   printf("%d)\n%s\n   |----%s(",num,b[i].dqname,b[i].sgname);
		   num = b[i].num;
	   }else {
	     if(strcmp(b[i].sgname,b[i-1].sgname) != 0 )
	     {
		    printf("%d)\n   |----%s(",num,b[i].sgname);
			num = b[i].num;
		 }else num += b[i].num;
	   }
	 }
    printf("%d)\n",num);
	if(t)
		printf("\n");
   }
return 0 ;
}
