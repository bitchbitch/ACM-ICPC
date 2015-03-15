// File Name: uva10361.c
// Author: darkdream
// Created Time: 2013年02月22日 星期五 14时11分15秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
    int n ;
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	getchar();
	while(n--)
	{
	  char a[1000],b[1000];
	  int i ,j , k , l , m ,n;
	  gets(a);
	  gets(b);
	  for (i = 0;i <strlen(a) ;i++)
		  if(a[i] != '>' && a[i] != '<')
			  printf("%c",a[i]);
	  printf("\n");
	  for(i =0 ;i < strlen(a);i++)
	  { 
		  if(a[i] == '<')
		  {
		    k = i ;
			break;
		  }
         	    
	  }
	  for(i = k ; i< strlen(a) ;i++)
	  {
	     if(a[i] == '>')
		 {
		   l = i ;
		   break;
		 }
	  }
		
	  for(i = l ; i< strlen(a) ;i++)
	  {
	     if(a[i] == '<')
		 {
		   m = i ;
		   break;
		 }
	  }
	
	  for(i = m ; i< strlen(a) ;i++)
	  {
	     if(a[i] == '>')
		 {
		   n = i ;
		   break;
		 }
	  }

	  for(i = 0;i < strlen(a)-2 ; i++)
	  {
	    if(b[i] == '.' && b[i+1] == '.' && b[i+2] == '.')
		{	j = i ;
		    break;
		}

	  }
	  for (i =0 ;i < j ;i++)
		  printf("%c",b[i]);
	  for (i = m+1 ;i < n ;i++)
		  printf("%c",a[i]);
	  for(i = l+1; i< m ;i++)
		  printf("%c",a[i]);
	  for(i = k+1; i < l ;i++)
		  printf("%c",a[i]);
	  for(i = n+1;i< strlen(a);i++)
		  printf("%c",a[i]);
      	printf("\n");
	}
	 
	return 0 ;
}
