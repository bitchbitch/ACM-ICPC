// File Name: uva537.c
// Author: darkdream
// Created Time: 2013年02月22日 星期五 14时48分32秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   int n , h;
   scanf("%d",&n);
   getchar();
   for ( h =1 ;h <= n; h++)
   {
     char a[1000];
	 double u,i,p;
	 char U[10],I[10],P[10];
	 int t ,j , k;
	 gets(a);
	 if(strstr(a,"U=") && strstr(a,"I="))
	 {  k = 0;
	    for ( t = strstr(a,"U=") - a +2;  a[t] != 'V'&& a[t] !='m' && a[t]!='k' && a[t] != 'M';t++ )
		  {
			U[k] = a[t];
			k++;
		  }
	
        U[k] = '\0';
	    u = atof(U);
		if(a[t] == 'm')
			u = u/1000;
        if(a[t] == 'k')
			u = u*1000;
		if(a[t]== 'M')
			u = u*1000000;
		k = 0;
	    for ( t = strstr(a,"I=") - a +2;  a[t] != 'A'&& a[t] !='m' && a[t]!='k' && a[t] != 'M';t++ )
		  {
			I[k] = a[t];
			k++;
		  }
        I[k] = '\0';
		i = atof(I);
		if(a[t] == 'm')
			i = i/1000;
        if(a[t] == 'k')
			i = i*1000;
		if(a[t]== 'M')
			i = i*1000000;
		printf("Problem #%d\nP=%.2fW\n\n",h,i*u);
        continue;
			
       }
	 if(strstr(a,"P=") && strstr(a,"U="))
	   
	 {  k = 0;
	    for ( t = strstr(a,"U=") - a +2;  a[t] != 'V'&& a[t] !='m' && a[t]!='k' && a[t] != 'M';t++ )
		  {
			U[k] = a[t];
			k++;
		  }
        U[k] = '\0';
	    u = atof(U);
		k = 0;
		if(a[t] == 'm')
			u = u/1000;
        if(a[t] == 'k')
			u = u*1000;
		if(a[t]== 'M')
			u = u*1000000;
	    for ( t = strstr(a,"P=") - a +2;  a[t] != 'W'&& a[t] !='m' && a[t]!='k' && a[t] != 'M';t++ )
		  {
			P[k] = a[t];
			k++;
		  }
        P[k] = '\0';
		p = atof(P);
		if(a[t] == 'm')
			p = p/1000;
        if(a[t] == 'k')
			p = p*1000;
		if(a[t]== 'M')
			p = p*1000000;
		printf("Problem #%d\nI=%.2fA\n\n",h,p/u);
        continue;
			
	 }
	 if(strstr(a,"P=") && strstr(a,"I="))
	 {  k = 0;
	    for ( t = strstr(a,"P=") - a +2;  a[t] != 'W'&& a[t] !='m' && a[t]!='k' && a[t] != 'M';t++ )
		  {
			P[k] = a[t];
			k++;
		  }
        P[k] = '\0';
	    p = atof(P);
		if(a[t] == 'm')
			p = p/1000;
        if(a[t] == 'k')
			p = p*1000;
		if(a[t]== 'M')
			p = p*1000000;
		k = 0;
	    for ( t = strstr(a,"I=") - a +2;  a[t] != 'A'&& a[t] !='m' && a[t]!='k' && a[t] != 'M';t++ )
		  {
			I[k] = a[t];
			k++;
		  }
        I[k] = '\0';
		i = atof(I);
		if(a[t] == 'm')
			i = i/1000;
        if(a[t] == 'k')
			i = i*1000;
		if(a[t]== 'M')
			i = i*1000000;
		printf("Problem #%d\nU=%.2fV\n\n",h,p/i);
        continue;
			
	 }

   }
   
   
return 0 ;
}
