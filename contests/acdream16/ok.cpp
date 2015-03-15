// File Name: ok.cpp
// Author: darkdream
// Created Time: 2014年07月12日 星期六 12时05分00秒

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
#include<climits>
#include<queue>
using namespace std;

int main(){
     FILE *f = fopen("cout.txt","r");
     FILE *f1 = fopen("cout1.txt","r");
	 char str[100],str1[100];
	 int i = 0 ; 
	 while(fgets(str,100,f))
	 {
		i ++ ;
	    fgets(str1,100,f1);
		if(strcmp(str,str1)!= 0 )
		{
			printf("**\n");
		    printf("%d\n",i);
		}
	 }
	 fclose(f);
	 fclose(f1);
return 0;
}
