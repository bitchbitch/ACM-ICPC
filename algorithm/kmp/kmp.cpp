// File Name: kmp.cpp
// Author: darkdream
// Created Time: 2015年05月01日 星期五 15时55分48秒

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
int net[1000];
char p[1000];
char s[1000];
void Getnet(char *p ){
	int len = strlen(p);
	memset(net,0,sizeof(net));
	net[0] = -1; 
	int k = -1; 
	int j = 0 ; 
	while(j < len -1){
		if(k == -1 || p[j] == p[k]){
			++ k ; 
			++ j ; 
			net[j] = k ; 
		}else{
			k = net[k];
		}
	}
}
//优化过后的net 数组求法  
void Getnet1(char* p)  
{  
    int pLen = strlen(p);  
    net[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
        //p[k]表示前缀，p[j]表示后缀    
        if (k == -1 || p[j] == p[k])  
        {  
            ++j;  
            ++k;  
            //较之前net数组求法，改动在下面4行  
            if (p[j] != p[k])  
                net[j] = k;   //之前只有这一行  
            else  
                //因为不能出现p[j] = p[ net[j ]]，所以当出现时需要继续递归，k = net[k] = net[net[k]]  
                net[j] = net[k];  
        }  
        else  
        {  
            k = net[k];  
        }  
    }  
}  
int kmp(char *s,char *p){
	int i = 0 ; 
	int j = 0 ;
	int slen = strlen(s);
	int plen = strlen(p);
	int sum = 0 ; 
	while(i < slen ){
		if( j == -1 || s[i] == p[j]){
			i ++ ; 
			j ++ ; 
		}else{
			j = net[j];
		}
		if(j == plen){
			sum ++ ; 
			j = net[j];
		}
	}
	return sum; 
}
int main(){
	scanf("%s",s);
	scanf("%s",p);
	Getnet1(p);
	for(int i = 0 ;i < strlen(p) ;i ++)
			printf("%d ",net[i]);
	printf("\n");
	printf("%d\n",kmp(s,p));
return 0;
}
