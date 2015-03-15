// File Name: 1.3.2.cpp
// Author: darkdream
// Created Time: 2013年01月23日 星期三 20时35分35秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

int cmp(const void *a, const void *b)
{
   return *(int *)a - *(int *)b;

}

int cmp1(const void *a, const void *b)
{
   return *(int *)b - *(int *)a;

}
int main(){
    
	int m ,i,j,s, k ,a[300],b[300];
    scanf("%d %d %d",&m,&s,&k);
	for (i = 0; i < k; i++)
		scanf("%d",&a[i]);
    qsort(a,k,sizeof(int),cmp);
    for (i = 1; i < k ;i++)
		b[i-1] = a[i] - a[i-1]-1;
	qsort(b,k-1,sizeof(int),cmp1);
	int sum = a[k-1] - a[0] +1 ;
	for (i = 0 ; i < m-1 ;i++)
		sum  = sum - b[i];
 printf("%d\n",sum);
    
return 0;
}
