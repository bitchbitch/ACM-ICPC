#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
#include <iomanip>
#include<iostream>
#include<algorithm>
using namespace std ;

int a,b ;
int  carry,ans ,now ;

int  get(int x , int p) 
{
    x++ ;
    int v = (1<< p) ,  num = 0 ;
    num = x/v * v /2 ;
    x = x % v ;
    if(x > (v/2)) num += x - (v/2) ;
    return num ;
}

int main()
{
    while(~scanf("%d%d",&a,&b)) 
    {
           carry = ans = 0 ;
           now=1;
           while( (1 << now) <= b || carry > 0 )
           {
                     carry += get(b,now)-get(a-1,now) ;
                  ans += carry >> 1 ;        
                     carry >>= 1 ;
                  now++ ; 
           } 
          cout << ans << endl ; 
    }
    return 0;
} 
