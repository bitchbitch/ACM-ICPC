#include <stdio.h>
#include <string.h>
int b[100005],c[100005];
int main()
{   int t; 
	scanf("%d",&t);
	while (t --)
	{ 
	   memset(b,0,sizeof(b));
	   memset(c,0,sizeof(c));
	   int s ,l ,m ,n,t = 0,k ,i ,j ;
	   scanf("%d",&m);
	
	   if (m < 0)
	   {
	       m = -m;
		   t = 1;
	   }
	   if (m == 1)
	   {
	     if (t)
			printf("-1\n");
		 else 
			 printf("1\n");
			
	   }
	   else 
	   {
	      k = 1;
		  j = 1 ;
		  while (k)
		  {
		    k = k *10;
            b[j++] = k / m; 
	        if (b[1] == 3)
				c[b[1]] =1; 
			k = k % m;
			if (c[k] || k == 1 )
				break;
			c[k] = 1; 
		   
		  }

		if (t)
			printf("-");
		printf("0.");
		for (i = 1 ;i < j ;i++)
			printf("%d",b[i]);
	    printf("\n"); 
	   }
	   
	}
	return 0 ;
}
