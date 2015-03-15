#include<stdio.h>
#include<ctype.h>
int main()
{
  char c, temp = ' ';
  while(c = getchar())
  {
    if (c != ' ' && temp == ' ')
		printf("%c",toupper(c));
	temp = c;
  }
return 0;
}
