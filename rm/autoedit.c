// File Name: autoedit.c
// Author: darkdream
// Created Time: 2013年02月24日 星期日 15时07分50秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char change[300] = {0};
char find[20][300] = {0};
char to[20][300] = {0};
int main(){
    int n; 
	while(scanf("%d",&n) != EOF, n)
	{  getchar();
	    memset(change,0,sizeof(change));
		memset(find,0,sizeof(find));
        memset(to,0,sizeof(to));
       for (int i = 1 ;i<= n;i++)
	   {

	     gets(find[i]);
		 gets(to[i]);
		 
	   }
	   gets(change);
	   int s = 1;
	   while(1)
	   {
	      int p = 0;
		  
          for(int  i = s;i <= n ;i++)
		  {
		     if(strstr(change,find[i]))
			 { s = i;
               p = 1;
				int k = strstr(change,find[i]) - change, t, s,l;
			   t = strlen(to[i]) - strlen(find[i]);
			   l  = strlen(change);
			   if(t > 0)
				   for(int j = l -1 +t; j>= k ; j-- )
					   change[j] = change[j-t];
               if(t < 0)
				   for(int j = k + strlen(find[i]) +t ; j < l ;j++)
					   change[j] = change[j-t];
			   for(int j = k ; j -k < strlen(to[i]) ;j++)
				   change[j] = to[i][j-k];
			   break;
			 }
		  }
		  if(!p)
			  break;
		  
	   
	   }
	   puts(change);
	}

return 0 ;
}
