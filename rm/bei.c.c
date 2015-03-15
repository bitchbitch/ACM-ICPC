#include <string.h>
#include <stdio.h>
char a[10000]={0};
struct st
{
    char num[100];
	int a[4];	
	int q,h;
};



int main()
{ char c;
	int i=0;
	FILE  *fp;
    struct st s[70] = {0};
	fp = fopen("x.in","r");
    
	c = fgetc(fp);
	while (c != EOF)
	{
		a[i++] = c;
		c = fgetc(fp); 
	}
	fclose (fp);

     int sum=0 ;
     int ok = 0,t,j,k=0;
	 for (i = 0 ; i <strlen(a); i++)
	    {
		  if (a[i] == '[')
			 {
			  ok=1;
			  j=0;
			  k=k+1;
			  s[k].q = i;
			  s[k-1].h = i-1;
			 }
		  if (ok &&  a[i] != ']' && a[i] != '[')
             s[k].num[j++] = a[i];
		  else if (a[i] == ']')
		  { ok = 0 ;
		      
		  }

		}
	s[69].h = strlen(a)-1;
    
	
	
	char *p1,*p2;
	int d[100],e[100],f[100],g[100];
	p1 = a;
	i = 1;
	while (strstr(p1,"金"))
	{
	  d[i++]= strstr(p1,"金")-a;
	  printf("%d ",d[i-1]);
      p1 =strstr(p1,"金")+sizeof("金");
	}
	   printf("%d\n", i-1);
	for (j = 1; j <= i - 1; j ++)
		for (k = 1; k <= 69 ; k++)
			if (d[j] <= s[k].h && d[j] >= s[k].q)
				s[k].a[0]++;
	
	p1 = a;
	i = 1;
	while (strstr(p1,"银"))
	{
	  e[i++]= strstr(p1,"银")-a;
      p1 =strstr(p1,"银")+sizeof("银");
	}
	   printf("%d\n", i-1);
	      
	for (j = 1; j <= i - 1; j ++)
		for (k = 1; k <= 69 ; k++)
			if (e[j] <= s[k].h && e[j] >= s[k].q)
				s[k].a[1]++;
	
	p1 = a;
	i = 1;
	while (strstr(p1,"铜"))
	{
	  f[i++]= strstr(p1,"铜")-a;
      p1 =strstr(p1,"铜")+sizeof("铜");
	}
	   printf("%d\n", i-1);
	      
	for (j = 1; j <= i - 1; j ++)
		for (k = 1; k <= 69 ; k++)
			if (f[j] <= s[k].h && f[j] >= s[k].q)
				s[k].a[2]++;
	
	p1 = a;
	i = 1;
	while (strstr(p1,"优胜"))
	{
	  g[i++]= strstr(p1,"优胜")-a;
      p1 =strstr(p1,"优胜")+sizeof("优胜");
	}
	   printf("%d\n", i-1);
	      
	for (j = 1; j <= i - 1; j ++)
		for (k = 1; k <= 69 ; k++)
			if (g[j] <= s[k].h && g[j] >= s[k].q)
			 s[k].a[3]++;
    for (i = 1; i<= 69 ; i ++ )
	   printf("{\"%s\",%d,%d,%d,%d},\n",s[i].num,s[i].a[0],s[i].a[1],s[i].a[2],s[i].a[3]);
   return 0;

}



