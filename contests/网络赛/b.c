#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>

#include <iostream>

#include <algorithm>

#define LL long long

#define Max(x, y) ((x) >= (y)) ? (x) : (y)

#define Min(x, y) ((x) <= (y)) ? (x) : (y)

#define MAX 100009

using namespace std;

int a[MAX], b[MAX + MAX], c[MAX];

int main()

{

	int T, numm = 1;

	scanf("%d", &T);

	while (T--)

	{

		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);
		int fa = n, ea = 1, fb = 100000, eb = 100001, fc = 1;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)

			a[i] = i;

		memset(b, 0, sizeof(b));

		memset(c, 0, sizeof(c));

		int flag = 1;
		int oka = 1;
		int okb = 1;
		while(1)
		{
			if(flag)
			{
				flag = !flog;
				if(oka)
				{   int i , k;
					for( i = fa ,  k = 1 ;  k <= x, i >= ea; k++, i --   )
				    {
					   b[++fb] = a[i]; 
					}
					if(i < ea)
					{
					   oka = 0 ;
					}
					
				}
				if(okb)
				{ int i , k ;
				   for(i = fb, k = 1; k <= y , i >= eb ; k++, i --)
				   {
				       c[++fc] = b[i];
				   }
				   if(i < eb)
				   {
				     okb = 0;
				   }
				}
				if(!oka && !okb)
				 break;
			}
			else
			{
				flag = !flog;
				if(oka)
				{   int i , k;
					for( i = ea ,  k = 1 ;  k <= x, i <= ea; k++, i --   )
				    {
					   b[++fb] = a[i]; 
					}
					if(i < ea)
					{
					   oka = 0 ;
					}
					
				}
				if(okb)
				{ int i , k ;
				   for(i = fb, k = 1; k <= y , i >= eb ; k++, i --)
				   {
				       c[++fc] = b[i];
				   }
				   if(i < eb)
				   {
				     okb = 0;
				   }
				}
				if(!oka && !okb)
				 break;
				
			}  
		}



		printf ("Case %d:", numm++);

		for (int i = n; i > 0; i--)

			printf ("! %d", c[i]);

		printf ("\n");

	}

	return 0;

}
