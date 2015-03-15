#include <stdio.h>
int main()
{
     int i;
     for (i=100;i*3<1000;i++)
	 {
        int a[10]={0},j;
     	
	   a[i%10]=1;
	   a[i/10%10]=1;
	   a[i/100]=1;
	    
	   a[3*i%10]=1;
	   a[3*i/10%10]=1;
	   a[3*i/100]=1;
	  
	   a[2*i%10]=1;
	   a[2*i/10%10]=1;
	   a[2*i/100]=1;
	  for (j=1;j<=9;j++)
		  if (a[j]!=1)
			  break;
	  if(j==10)
     printf("%d %d %d\n",i,2*i,3*i);
	    
	 }
	 
	  
	 return 0;



}
