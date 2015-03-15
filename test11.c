#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#define max(a , b) (a)>(b)?(a):(b)
#define min(a , b) (a)<(b)?(a):(b)
#define LL long long
#define INT_MAX 0x7fffffff
using namespace std;

int integer[2][10] , i , j;
char digit[2][500];

int main()
{
while (~scanf("%s%s" , digit[0] , digit[1]))
{
memset(integer , 0 , sizeof(integer));
for(i=0 ; digit[0][i] ; i++)
{
if(digit[0][i] == '5')	integer[0][2]++;
else if(digit[0][i] == '9')	integer[0][6]++;
else	integer[0][digit[0][i] - '0']++;
}
for(i=0 ; digit[1][i] ; i++)
{
if(digit[1][i] == '5')	integer[1][2]++;
else if(digit[1][i] == '9')	integer[1][6]++;
else	integer[1][digit[1][i] - '0']++;
}
int temp=INT_MAX;
for(i=0 ; i<9 ; i++)
if(integer[0][i])
temp=min(temp , integer[1][i]/integer[0][i]);
printf("%d\n", temp);
}
return 0;
}
