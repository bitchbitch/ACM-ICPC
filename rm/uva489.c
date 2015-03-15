#include <stdio.h>
#include<string.h>

int main()
{
  int i, n,j,sum; 
  char a[80];
  bool s[26];
   
  while (scanf("%d",&n),n!=-1)
  {
    memset(s,0,sizeof(s));
	

    scanf("%s",a);
	sum = 0 ;
	for (i = 0; a[i]>='a' && a[i]<='z'; i++)
	{ if (s[a[i] - 'a'] == 0) 
		{s[a[i]-'a'] = 1;
          sum ++;
	   }
	}
	scanf ("%s",a);
    j = 0;

    for (i  =0 ;a[i]>='a' && a[i]<='z';i ++)
	{
	  if (s[a[i]-'a'] == 1)
		  s[a[i]-'a'] = 0 ,sum --;
	  else 
        j++;
	  if (sum==0 ||  j ==7)
		  break;

	}

	printf("Round %d\n",n);
	if(sum == 0 )
		printf("You win.\n");
	else if(j== 7 )
		printf("You lose.\n");
	else 
		printf("You chickened out.\n");
  }
  return 0 ;
}
