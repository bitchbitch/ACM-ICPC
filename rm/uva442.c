// File Name: uva442.c
// Author: darkdream
// Created Time: 2013年05月15日 星期三 21时15分38秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node 
{
  int a, b;
}m[300] ;
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n; 
   scanf("%d",&n);
   char str[1000];
   getchar();
   for(int i = 1;i <= n;i ++)
   {
	char c;
    c = getchar();
	scanf("%d %d",&m[c-'A'+1].a,&m[c-'A'+1].b);
	getchar();
   }
   int a[1000];
   int b[1000] ;
   while(scanf("%s",str) != EOF)
   {
	 int sum = 0 ,k = n+1, ok = 1;
	 struct node temp;
     if(strlen(str) == 1)
		 printf("0\n");
	 else
	 {
	     for(int i = 0 ;i < strlen(str); i ++)
		 {
		    if(str[i] == '(')
				a[i] = -1 ;
			else if(str[i] == ')')
				a[i] = -2;
			else
				a[i] = str[i]-'A' +1;
		 }
		 int j = -1 ;
         for(int  i = 0 ;i <strlen(str) ; i++)
		 {
		    if(a[i] == -1)
			{
			   j++ ;
			   b[j] = a[i];
			}
			else if(a[i] == -2)
			{
			    b[j-1] = b[j];
				b[j] = 0 ;
				j--;
				if(b[j-1] > 0)
				{
			     if(m[b[j]].a == m[b[j-1]].b)
					{
						sum += m[b[j-1]].a*m[b[j-1]].b*m[b[j]].b;
					    m[k].a = m[b[j-1]].a;
						m[k].b = m[b[j]].b;
						b[j-1] = k;
						b[j] = 0;
						j--;
						k++;
					
					}
				 else
				  {
				    ok = 0 ;
					break;
				  }
				   
				}

			}
			else
			{
			  if(b[j] > 0 )
			  {
			     if(m[a[i]].a == m[b[j]].b)
					{
					    sum += m[b[j]].a*m[b[j]].b*m[a[i]].b;
					    m[k].a = m[b[j]].a;
						m[k].b = m[a[i]].b;
						b[j] = k;
						k++;
					
					}
				 else
				  {
				    ok = 0 ;
					break;
				  }
			  }
			  else
			  {
			    j++;
				b[j] = a[i];
			  }
			}
		 }

	 if(ok)
		 printf("%d\n",sum);
	 else
		 printf("error\n");
	 }

   }

   
return 0 ;
}
