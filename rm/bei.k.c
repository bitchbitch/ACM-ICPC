#include <stdio.h>
#include <string.h>
char a[1000000]={0};
int main()
{ 
	 int i=0 ;
	 char c, *p1, *p2;
	 memset(a ,0 ,sizeof(a));
	 c = getchar();
	 while (c != EOF)
	 {
	     a[i++] = c;
		 c = getchar ();

	 }
	 p1 = a;
	 while (strstr(p1,"Accepted"))
	  {
	    p1 = strstr(p1,"Accepted") - 628;
	    p2 = strstr(p1,"lang_");
		 p2 = p2+5;
          
		 while (*p2 != '\'')  
	      {
		   printf("%c", *p2);
		   p2 = p2+1;
		  }
		  printf(" ");
	      p2= strstr(p1,"/problem/");
          p2 = p2 + 9;
		  p1 = p2;
		
		  if (*p2 == '\"')
		  { 
	       p2= strstr(p1,"/problem/");
           p2 = p2 + 9;
		   printf("%c ",*p2);
          }
		  else
		  printf("%c ",*p2);
		  
		  
		  p2 = strstr(p1,"/profile/") + 9;
		  while (*p2 != '/')  
	      {
		   printf("%c", *p2);
		   p2 = p2+1;
		  }
		  
		printf("\n");
		p1 = strstr(p1, "Accepted")+8 ;
	  }
	
   return 0 ;

}
