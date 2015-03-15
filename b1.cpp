#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int main()
{
	int a[]={0,5,10,20,50,100,200,500,1000,2000,5000,10000};
	int f[6666];
	freopen("input.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	//memset(f,0,sizeof(f));
	for(int i=1; i<= 6000; i++)
		f[i]= 0;
	f[0]= 1;
	for(int i=1; i<= 11; i++)
		for(int j= 6000; j>= 1; j--)
			for(int k =1; k<= j/a[i]; k++)
				if(j>=k*a[i]&&f[j-k*a[i]]>0)
					f[j]+= f[j-k*a[i]]; 
	double n;
	while(scanf("%lf",&n)!=EOF&&n)
	{
		double m= n;
		m*= 100;
		int t;
		t = m;
		printf("%5.2lf%12d\n",n,f[t]);
	}
return 0;
}

