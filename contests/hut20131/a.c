// File Name: a.c
// Author: darkdream
// Created Time: 2013年09月03日 星期二 12时38分18秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char str[2005];
int a[2005];
int len ; 
int ok (int k )
{
   if(k %2 == 0 )
	   return 1;
   else return 0 ;
}
void jian()
{
   int temp = 1 ;
   for(int i = 1;i <= len ;i++)
   {
      if(a[i] >= 1)
	  {
	     a[i] -= 1;
		 break;
	  }
	  else 
	  {
	     a[i] = 9;
	  }
   }
}
void chu()
{
   int temp = 0; 
   for(int i = len ; i >= 1;i -- )
   {
	  temp = temp*10 + a[i];
      if(temp % 2 == 0)
	  {  
		  a[i] = temp /2;
	      temp = 0 ;
	  }
	  else 
	  {
	      a[i] = temp/2;
		  temp = 1;
	  }
	   
   }
}
void print()
{
   int i ; 
   for(i = len ;i >= 1;i -- )
	   if(a[i] != 0)
		   break;
   for(int j =i ;j >= 1;j --)
	   printf("%d",a[j]);
   printf("\n");
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n ;
   scanf("%d",&n);
   for(int Case = 1;Case <= n;Case++)
   {
	 memset(a,0,sizeof(a));
     scanf("%s",str);
     len = strlen(str);
	 for(int i = len - 1;i >= 0 ;i--)
        a[len-i] = str[i]-'0';
	 if(ok(a[1]))
	 {
	    chu();
		if(ok(a[1]))
		{
			jian();
		}
		else 
		{
		 jian();
		 jian();
		}
	 }
	 else
	 {
		 jian();
		 chu();
	 }
	 
	 if(Case != 1)
		 printf("\n");
	 print();
   }
return 0 ;
}
