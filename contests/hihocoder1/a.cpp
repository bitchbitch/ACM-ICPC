#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 30; 
	set<int>s;
//	freopen("a.out","w",stdout);
	for(int i = 0 ;i <= 10000000;i++)
	{
	   int t = i;
	   int k = 0 ;
	   int suma = 0 ;
	   int sumb = 0 ;
	   int a[10] = {0} ; 
	   while(t)
	   {
		 k ++ ;
	     a[k] = t % 10 ;
		 t = t /10;
	   }
	   int p = 0 ; 
	   for(int j = k; j >= 1; j -- )
	   {
		 p ++ ; 
	     if(p % 2 == 1)
			 suma += a[j];
		 else sumb += a[j];
	   }
	   if(suma - sumb == n)
		   printf("%d\n",i);
	}
   
return 0;
}
