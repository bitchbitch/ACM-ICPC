#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;
#define maxn 100000

long long sum[maxn+5];
int  pos[maxn+5];
char ch[maxn+5];
long long k;
bool ok(int l,int r)  
{  
    int mid = (l + r)/2;  
    int cur_mid = pos[mid];  
    int num = mid - l; //mid左边的1的个数   
    long long temp = cur_mid * num - num*(num + 1)/2 - (sum[mid - 1] - sum[l - 1]); //中点左边要移动的次数   
    num = r - mid;  
    temp+=sum[r] - sum[mid] - num * cur_mid - num*(num + 1)/2;  
    if(temp > k) return false;  
    else return true;  
}  

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		memset(pos, 0, sizeof(pos));
		scanf("%s %lld",ch+1, &k);
		int len= strlen(ch+1);
		int count= 0; 
		sum[0]= 0;
		for(int i= 1; i<= len; i++)
		{
			if(ch[i]=='1')
			{
				count++;
				pos[count]= i;
				sum[count]= sum[count-1]+pos[count];
			}
		}
		int max= 1;
		int be= 1;
		int ans= 0;
		//printf("%d\n", count);
		while(true)
		{
			if(max+ be -1>count)
				break;
			if( ok(be, be+max-1))
			{
				ans= max;
				max++;	
			}
			else		
				be++;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

