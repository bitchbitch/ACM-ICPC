#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{ 
	char a[100],b[100]={0};
	int i , j=0, k, l, m, c[100], max= 0, ti=0, tj=0;
	fgets(a,sizeof(a),stdin);
	for (i = 0 ; i < strlen(a); i++)
		if ((a[i] <= 'z' && a[i] >= 'a')||(a[i] <= 'Z' && a[i] >= 'A'))
		{   
			c[j]=i;
			b[j++]=toupper(a[i]);
		}
	puts(b);
	for (i = 0 ; i < strlen(b); i++  )
		{ 
		   for (j = 0 ; i+j < strlen(b), i-j >= 0 ; j ++ )
              if (b[i+j] == b[i-j])
			  {
			    if (2*j+1>max)
				{
			      max = 2*j +1 ;
				  ti = i - j ;
				  tj = i + j ;
				
				}

			  }
		    else  
			  break;
		
		   for ( j = 1 ; i+j < strlen(b),i-j+1 >= 0; j++ )
              if (b[i+j] == b[i-j+1])
			  {
			    if (2*j>max)
				{
			      max = 2*j ;
				  ti = i - j+1 ;
				  tj = i + j ;
				
				}

			  }
		    else  
			  break;
		
			
           
		   
            

		}
	printf("%d %d %d", max, c[ti]+1,c[tj]+1);
	return 0;
}




