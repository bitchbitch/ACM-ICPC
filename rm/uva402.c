// File Name: uva402.c
// Author: darkdream
// Created Time: 2013年01月25日 星期五 11时29分04秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char a[300];
int  b[300],temp[300];
void change()
{
    memset(temp,0,sizeof(temp));
	int i = 1;
    for (i = 0 ;i  < strlen(a); i++)
		temp[strlen(a)-i -1 ] = a[i] - '0';

}

void add()
{
	int i ;
	int s  = 0 ;
	for (i = 0 ; i < 250 ; i++)
	{
	  int t = temp[i]+b[i] +s; 
      s = t / 10;
	  b[i] = t % 10 ;

	}
}
void print()
{
  int i ;
  for (i = 250 ;i >= 0 ; i-- )
	  if (b[i] != 0)
		  break;
  for (; i >= 0 ;i--)
	  printf("%d",b[i]);
  printf("\n");

}
int main(){
  memset(b,0,sizeof(b));
  while (gets(a))
  {
     if (strlen(a) ==1 && a[0] == '0')
	 {	print();
	    break;
	 } change();
	  add();
  }
   
return 0 ;
}
