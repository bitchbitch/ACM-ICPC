// File Name: uva10010.cpp
// Author: darkdream
// Created Time: 2013年01月25日 星期五 09时25分33秒

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
#include<ctype.h>

using namespace std;
char a[100][100];
int m , k ;
int find (char b[] , int h , int l )
{
   int i , j ,  t =0 , s;
   if ( h+1 >= strlen(b) ) 
   {
      t = 1 ;
	  i = h ; 
	  j = l ;
	  for (s = 1 ; s < strlen(b); s++ )
		  if (b[s] == a[--i][j])
               t = t+1;
	  if (t == strlen(b))
           return 1;
   }
   if (h+1 >= strlen(b) && l+1 >= strlen(b))
   {
   
      t = 1 ;
	  i = h ; 
	  j = l ;
	  for (s = 1 ; s < strlen(b); s++ )
		  if (b[s] == a[--i][--j])
               t = t+1;
	  if (t == strlen(b))
           return 1;
   }
   if (l+1 >= strlen(b))
   {
    
      t = 1 ;
	  i = h ; 
	  j = l ;
	  for (s = 1 ; s < strlen(b); s++ )
		  if (b[s] == a[i][--j])
               t = t+1;
	  if (t == strlen(b))
           return 1;
   }
   if (h +1 >= strlen(b) && k-l+1 >= strlen(b))
   {
   t = 1 ;
   i = h ; 
   j = l ;
   for (s = 1 ; s < strlen(b); s++ )
	   if (b[s] == a[--i][++j])
			t = t+1;
   if (t == strlen(b))
		return 1;
   
   }
   if (k-l +1 >= strlen(b))
   {
   
      t = 1 ;
	  i = h ; 
	  j = l ;
	  for (s = 1 ; s < strlen(b); s++ )
		  if (b[s] == a[i][++j])
               t = t+1;
	  if (t == strlen(b))
           return 1;
   }
  if (m-h+1 >=strlen(b))
  {
  
      t = 1 ;
	  i = h ; 
	  j = l ;
	  for (s = 1 ; s < strlen(b); s++ )
		  if (b[s] == a[++i][j])
               t = t+1;
	  if (t == strlen(b))
           return 1;
  }
  if (m-h+1 >= strlen(b) &&  h+1 >= strlen(b))
  {
  
      t = 1 ;
	  i = h ; 
	  j = l ;
	  for (s = 1 ; s < strlen(b); s++ )
		  if (b[s] == a[++i][--j])
               t = t+1;
	  if (t == strlen(b))
           return 1;
  }
  if (m-h+1 >=strlen(b) && k -l +1 >= strlen(b))
  {
  
      t = 1 ;
	  i = h ; 
	  j = l ;
	  for (s = 1 ; s < strlen(b); s++ )
		  if (b[s] == a[++i][++j])
               t = t+1;
	  if (t == strlen(b))
           return 1;
  }
   return 0;
   
         

}

int main(){
	  char  b[100][100];
	  int n,i ;
	  scanf("%d",&n);
	  for (i = 1;i <= n;i++)
      {  memset(a,0,sizeof(a));
		 memset(b,0,sizeof(b));
		if(i != 1 )
			printf("\n");
      

	    int  j , c, t , p , q  ;
		scanf("%d %d",&m ,&k);
		getchar();
		for (j =0; j < m ; j++)
		{    gets(a[j]);
		   for (t = 0 ;t < k ; t++)
			   a[j][t]  = toupper(a[j][t]);
        }
		scanf("%d",&c);
		getchar();
		for (j = 0 ; j < c ;j++)
		{	gets(b[j]);
            for (t = 0 ; t < strlen(b[j]); t++)
				b[j][t] = toupper(b[j][t]);
         
		}
		for (j = 0 ; j < c ; j++)
		{
			for(t = 0 ;t < m ;t++)
			{  for (p = 0 ; p < k ; p++)
			  {
			    if (a[t][p] == b[j][0])
					if (find(b[j], t , p))
					{
						printf("%d %d\n",t+1, p+1);
						break;
					}
			  }
			  if(find(b[j],t,p))
				  break;
			}

		}
   
	
	    

	  }
return 0;
}
