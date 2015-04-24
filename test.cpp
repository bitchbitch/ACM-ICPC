
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
	int hs[300];
}a,b;
char S[10000];
char T[10000];
int ok()
{
	for(int i = 0 ;i <300 ;i ++)
		if(b.hs[i] < a.hs[i])
			return 0 ; 
	return 1; 
}
int main(){
	scanf("%s %s",S,T);
	int S_len ,T_len ; 
	S_len = strlen(S);
	T_len = strlen(T);
	for(int i = 0;i < T_len;i ++){
		a.hs[T[i]] = 1;
	}
	int l,r;
	int lans ,rans ;
	int mi = 1e9;
	int ansok = 0 ; 
	lans = rans = -1 ; 
	l = r = 0 ; 
	b.hs[S[0]] = 1; 
	while(r < S_len){
		
		while(ok() && l <= r )
		{
			ansok = 1; 
			if(r - l + 1  < mi)
			{
				mi = r - l + 1; 
				lans = l ; 
				rans = r; 
			}
			b.hs[S[l]] --; 
			l ++;
		}
		r ++ ; 
		b.hs[S[r]] ++ ; 
	}
	if(ansok)
		for(int i = lans  ;i <= rans ;i ++)
			printf("%c",S[i]);
	printf("\n");
return 0;
}
