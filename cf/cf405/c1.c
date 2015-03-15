// File Name: c.c
// Author: darkdream
// Created Time: 2014年03月23日 星期日 00时15分14秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int n ; 
int a[1001][1001];
int ans[1001];
int ans1[1001];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n ;j ++)
            scanf("%d",&a[i][j]);

    
    int sum = 0 ;
    memset(ans,0,sizeof(ans));
    memset(ans1,0,sizeof(ans1));
    
    
    for(int i = 1;i <= n;i ++)
    {
       
      for(int j = 1 ;j <= n; j ++)
          ans1[i] += a[i][j] *a[j][i];
      sum += ans1[i];
    }
    sum = sum % 2; 
    for(int i = 1;i <= n;i ++)
        for (int j = 1;j <= n;j ++)
        {
            ans[i] += a[i][n-j+1] * a[j][i];
        }
    for(int i = 1;i <= n;i++)
        ans[i] = abs(ans1[i] - ans[i] ) % 2;
    
   int q; 
   scanf("%d",&q);
   for(int i = 1;i <= q;i ++)
   {
      int temp ; 
      scanf("%d",&temp);
      if(temp == 1 || temp == 2)
            {
              int num ; 
              scanf("%d",&num);
              sum = (sum + ans[num]) % 2; 
            }
      if(temp ==  3)
          printf("%d",sum);
   }
   printf("\n");
return 0 ;
}
