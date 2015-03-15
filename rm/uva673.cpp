#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char str[1000];
int main()
{
    int t ;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        memset(str,0,sizeof(str));
        gets(str);
		int ok = 0;
	    int k = strlen(str);
		int sum = 1;
		while(sum != 0)
		{
		   sum = 0; 
		   for(int i = 0 ;i < k;i ++)
		   {
		     if(str[i] == '(')
			 {
			   for(int j = i+1 ;j < k ; )
			   {
			     if(str[j] == ')')
				 {
				   str[i] = '0';
				   str[j] = '0';
				   sum ++;
				   break;
				 }
				 else if(str[j] == '0')
					 j++;
			     else
					break;
			   
			   }

			 }
		     if(str[i] == '[')
			 {
			   for(int j = i+1 ;j < k ; )
			   {
			     if(str[j] == ']')
				 {
				   str[i] = '0';
				   str[j] = '0';
				   sum ++;
				   break;
				 }
				 else if(str[j] == '0')
					 j++;
			     else
					break;
			   
			   }

			 }

		   }
		   //puts(str);
		}
		for(int i = 0 ;i < k ;i ++)
			if(str[i] != '0')
		      ok = 1;
		if(ok == 1)
           printf("No\n");
		else
			printf("Yes\n");
    }
    return 0;
}
