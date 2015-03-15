// File Name: uva372.c
// Author: darkdream
// Created Time: 2013年05月21日 星期二 20时57分27秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char str[10000];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   while(gets(str))
   {
      bool a[30] = {0};
	  int num[30];
	  int add[30] = {0};
	  char temp[10000] = {0};
	  char temp1[10000] = {0};
	  char temp2[10000] = {0};
	  memcpy(temp,str,10000);
	  for(int i = 1;i <= 28;i ++)
	  {
	     num[i] = i ;
	  }
	 int sum = 0, j = -1 ;
     for(int i = 0 ;i < strlen(str); i ++)
	 {
           if(str[i] != ' ')
		   {
		    j++;
			str[j] = str[i];
		   }
	 }
	 str[j+1] = '\0' ;
	  for(int i = 0;i < strlen(str); i++)
      {
	     if(isalpha(str[i]))
		 {
			int k = str[i] - 'a' +1;
		     a[k] = 1;
	        if(i > 1)
			{
			  if(str[i-1] == '+' && str[i-2] == '+')
			  {
			      num[k]++; 
				  str[i-1] = str[i-2] = ' ';
			  }
			  else if(str[i-1] == '-' && str[i-2] == '-')
			  {
			      num[k]--;
				  str[i-1] = str[i-2] = ' ';
			  }

			}
			if(strlen(str) - i >= 3)
			{
			  if(str[i+1] == '+' && str[i+2] == '+')
			  {
			      add[k]++;
				  str[i+1] = str[i+2] = ' ';
			  }
			  else if(str[i+1] == '-' && str[i+2] == '-')
			  {
			      add[k]--;
				  str[i+1] = str[i+2] = ' ';
			  }
			
			}
		 }

	  }
	  memset(temp1,0,sizeof(temp1));
	  j = -1 ;
     for(int i = 0 ;i < strlen(str); i ++)
	 {
           if(str[i] != ' ')
		   {
		    j++;
			str[j] = str[i];
		   }
	 }
	 str[j+1]  = '\0';
	 sum = num[str[0]-'a'+1];
	 for(int i = 1;i < strlen(str) ;i ++)
	 {
	    if(isalpha(str[i]))
		{
		  if(str[i-1] == '-' )
			  sum -= num[str[i]-'a'+1];
		  else
			  sum += num[str[i]-'a'+1];
		}
	 }
	 for(int i = 1; i< 28;i ++)
	 {
	    num[i] = num[i]+ add[i];
	 }
	 printf("Expression: %s\n",temp);
	 printf("    value = %d\n",sum);

	 for(int i =1 ;i < 28; i ++)
	 {
	    if(a[i])
		{
		  printf("    %c = %d\n",i-1+'a',num[i]);
		}
	 }

   }
return 0 ;
}
