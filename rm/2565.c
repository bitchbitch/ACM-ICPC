#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{ 
	char a[100],b[100]={0};
  int i , j=0, k, l, m, c[100], max= 0, ti, tj;
  fgets(a,sizeof(a),stdin);
  for (i = 0 ; i < strlen(a); i++)
	  if ((a[i] <= 'z' && a[i] >= 'a')||(a[i] <= 'Z' && a[i] >= 'A'))
	  {   
		  c[j]=i;
		  b[j++]=toupper(a[i]);
	  }
  puts(b);
  for (i = 0 ; i < strlen(b)-1; i++  )
	  for (j = i+1 ; j <strlen(b); j++)
	  {   
		  int ok = 1;
	       for (k = i ; k <= j ; k ++)
			    if (b[k] != b[j-k+i])
					ok = 0 ;
	       if (ok)
			  if (j-i+1 > max)
			  {
			    max = j-i+1;
				ti = c[i];
				tj = c[j];

			  }
	  }
  printf("%d %d %d", max, ti+1, tj+1);
  return 0;
}



