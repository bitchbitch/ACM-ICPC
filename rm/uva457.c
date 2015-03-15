#include <stdio.h>
#include <string.h>

char a[100] , c[100],h[200];
int	 b[130];
int is()
{
   int i ; 
   for (i = 0 ;i < strlen(a); i++)
	   if (a[i] == '0')
		   a[i] = 'O';
   for (i = 0; i < strlen(a);i ++)
       if(a[i] != a[strlen(a)-i-1])
		   return 0 ;
 
		return 1; 
}
void change()
{
   int i ,j = 0 ; 
   memset(c,0,sizeof(c));
   for (i = 0 ; i < strlen(a)/2 ;i++)
   {
     if (b[a[i]])
		 a[i] = b[a[i]];
   }

}
int main()
{   
      memset(b,0,sizeof(b));
	b['A'] = 'A';
	b['E'] = '3';
	b['H'] = 'H';
	b['I'] = 'I';
	b['J'] = 'L';
	b['L'] = 'J';
	b['M'] = 'M';
    b['O'] = 'O';
	b['T'] = 'T';
	b['U'] = 'U';
	b['V'] = 'V';
	b['W'] = 'W';
	b['X'] = 'X';
	b['Y'] = 'Y';
	b['S'] = '2';
    b['Z'] = '5';
	b['2'] = 'S';
	b['3'] = 'E';
	b['5'] = 'Z';
	int d = 1 ; 

      while (gets(a))
	  {
         memcpy(h,a,sizeof(a));
	     int t = 0  ;
		 
		 if (is())
			 t = 1;
		 change();
         
		 if (is())
			 t = t + 2;
		 if (t == 3)
			printf("%s -- is a mirrored palindrome.\n",h);
		 else  if (t == 1)
			 printf("%s -- is a regular palindrome.\n",h);
		 else if (t == 2 )
			 printf("%s -- is a mirrored string.\n",h);
		 else 
			 printf("%s -- is not a palindrome.\n",h);
         
		
	   
	  }
	  return 0 ;

}


