#include <stdio.h>
#include <string.h>
char t[1000][1000];
int main()
{
  int k ;
  scanf("%d",&k);
  while (k--)
  {
	
    memset(t,'0',sizeof(t));  
    
	int  m ,i , j , k ;
    char a[10][4],b[10],c[1000]; 
	scanf("%d",&m);
	getchar();
	for (i = 1 ;i <= 8 ;i ++)
	{
	   scanf("%s %c",a[i],&b[i]);
	   getchar ();
	}
	gets(c);
    
    int l = strlen(c);
    
	for (j = 0 ;j< l ; j++)
       t[1][j+1] = c[j]; 
	for (i = 1; i <= m ;i ++)
		t[i][l+2] = '\0';
    
	
	for (i = 2; i<= m; i ++)
	{
	   for (j = 1 ; j<= l ; j++)
		   t[i][j] = '0';
	   for (j =1; j <= 8 ;j ++)
	     { char *p = t[i-1];
		   while( strstr(p,a[j]))
		   { 
		 	   t[i][strstr(p,a[j])-t[i-1]+1] = b[j];
		       p=p+1;
		   }
		   
		 }

	}

   for (j = 1 ; j<=m;j++)
     {for (i = 1;i <= l ;i++ )
		  printf("%c",t[j][i]);
	  printf("\n");
     }	  

  }
  return 0 ;

}

