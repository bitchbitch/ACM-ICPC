// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年04月17日 星期五 08时51分00秒

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
#define LL long long

using namespace std;
struct node{
	int year;
	int month;
	int day ; 
}be,en; 
char str[100];
char mon[][100] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
int sum[500];
void init(){
	sum[0] = 1; 
	for(int i =1 ;i <= 399 ;i ++){
		if(i% 400 == 0 ||(i % 100 != 0 && i % 4 == 0)){
			sum[i] = sum[i-1] + 1 ;  	
		}else{
			sum[i] = sum[i-1]; 
		}
	}
/*	for(int i = 0 ;i <= 399 ;i ++)
		printf("%d ",sum[i]);
	printf("\n");
*/
}
int count(int l ,int r ){
	//printf("%d %d\n",l,r);
     if(l > r)
	 {
		return 0 ; 
	 } 
	 int lans = (l- 1 - 2000)/400 * sum[399] + sum[(l-1-2000)%400];
	 int rans = (r - 2000)/400*sum[399] + sum[(r-2000) % 400];
	 return rans - lans; 
}
int ok(int year)
{
	if(year % 400 == 0 ||(year % 100 != 0 && year % 4 == 0))
		return 1; 
	return 0 ; 
}
int main(){	
    int T;
	scanf("%d",&T);
	init();
	for(int ca = 1; ca <= T ; ca ++){
		scanf("%s %d, %d",str,&be.day,&be.year);
		for(int i = 1;i <= 12 ;i ++)
			if(strcmp(str,mon[i]) ==  0 )
			{
				be.month = i ; 
			}
		scanf("%s %d, %d",str,&en.day,&en.year);
		for(int i = 1;i <= 12 ;i ++)
			if(strcmp(str,mon[i]) ==  0 )
			{
				en.month = i ; 
			}
	//	printf("%d %d %d\n",be.year,be.month,be.day);
	//	printf("%d %d %d\n",en.year,en.month,en.day);
		int ans = count(be.year+1,en.year - 1);
		//printf("%d\n",ans);;
	    if(en.year == be.year){
			if(ok(en.year)){
				if(en.month > 2){
					 if(be.month < 2){
						ans ++ ;  
					 }else if(be.month == 2){
						if(be.day <= 29)
							ans ++ ;
					 }
				}else if (en.month == 2 && en.day == 29)
					ans ++ ; 
			}
		}else{
			if(ok(en.year)){
			    if(en.month > 2)
					ans ++ ; 
				else if(en.month == 2 && en.day == 29)
					ans ++ ;
			}
			if(ok(be.year)){
		        if(be.month == 1)
					ans ++ ;
				else if(be.month == 2 && be.day <= 29 )
					ans ++ ; 
			}
		}
		printf("Case #%d: %d\n",ca,ans);
	}
return 0;
}
