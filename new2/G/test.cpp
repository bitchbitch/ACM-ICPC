#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
int main(){
	int n,i;
	freopen("in","r",stdin);
	freopen("out1","w",stdout);
	while (~scanf("%d",&n)){
		char ss[20],s[20];
		int ans=0,k;
		for (i=0;i<n;i++){
			getchar();
			scanf("%s%d",s,&k);
			if (ans<k){
				ans=k;
				strcpy(ss,s);
			}
		}
		cout<<ss<<endl;
	}
	return 0;
}

