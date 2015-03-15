// File Name: uva112.c
// Author: darkdream
// Created Time: 2013年05月16日 星期四 22时26分01秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node 
{
  char c;
  int num ;
};
void get(char *s)
{ char c;
  int j = -1 ;
  int k = -1 ;
  char temp[5000] = {0};
  while(c=getchar())
  {
     if(c != ' ' && c!= '\n')
	 {
	   j++;
	   s[j] = c;
	 }
	 if(c == ')')
	 {
		 if(s[j-1] == '(')
		 {
		   s[j] = '\0';
		   s[j-1] = '\0';
		   j = j-2;
		 }
	     if(k == 0 )
			 break;
		 else
		 {  temp[k] = '\0';
			 k--;
		   
		 }

	 }
	 else if(c == '(')
	 {
	     k++;
		 temp[k] = c;

	 }
  }
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  int n; 
  while(scanf("%d",&n) != EOF)
  {

    int ok = 0 ;
	char str[5000] ={0};
    struct node nodes[5000] = {0};
	struct node ans[5000] = {0};	
	get(str);
	//puts(str);

	int j = -1;
	for(int i = 0 ;i < strlen(str); i ++)
	{
	   if(str[i] == '('  || str[i] == ')')
	   {
		   j++;
		   nodes[j].c = str[i];
	           
       }
	   if(str[i] == '('&& str[i+1] != ')')
	    {
		   int k = -1 , num  = 1,temp = 0 ;
		   if(str[i+1] == '-')
		   {  
			  num = -1;
		      i = i+1;
		   }
	       for(int t = i+1; ; t++)
		     {
			    if(str[t] == '(' || str[t] == ')')
				{
					i = t-1;
					break;
				}
				else
				{
				  temp = temp *10 + str[t] -'0';
				}
			 }
		   j++;
		   nodes[j].c = 'x';
		   nodes[j].num = num*temp;
		

	    }


	}
	int k = -1;
	for(int i = 0 ;i <= j; i ++)
	{
	  if(nodes[i].c == '(')
	  {
		  k++;
		  ans[k].c = '(';
	  }
	  else if(nodes[i].c == ')')
	  {

	      k = k -2;
	  }
	  else 
	  {
		  k++;
		  ans[k].c = 'x';
		  if(k == 1)
		  {   
			  ans[k].num = nodes[i].num; 
		  }
		  else
	 	  {
			     ans[k].num = nodes[i].num + ans[k-2].num;
				 //printf("%d ",ans[k].num);
		  }
		  
		  
		  if(nodes[i+1].c == ')')
		  {
		    if(ans[k].num == n)
				ok = 1;
		  }

	  }

	}
	/*for(int i = 0 ; i<= j;  i ++)
		printf("%c",nodes[i].c);
    printf("\n");
	for(int i= 0 ; i <= j;i ++)
		printf("%d ",nodes[i].num);*/
	if(ok == 1)
		printf("yes\n");
	else
		printf("no\n");

  }
return 0 ;
}
