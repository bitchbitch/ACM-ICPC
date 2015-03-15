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
#define maxn 1010
using namespace std; 

struct BigNumber{
	int len;
	int v[maxn];
};
bool isSmaller(BigNumber num1,BigNumber num2)
{
	if(num1.len<num2.len)
		return 1;
	if(num1.len>num2.len)
		return 0;
	for(int i=num1.len-1;i>=0;i--)
	{
		if(num1.v[i]<num2.v[i])
			return 1;
		if(num1.v[i]>num2.v[i])
			return 0;
	}
	return 0;
}
BigNumber minnum(BigNumber num1,BigNumber num2)
{
	BigNumber ret;
	int borrow,i,temp;
	ret=num1;
	for(borrow=0,i=0;i<num2.len;i++)
	{
		temp=ret.v[i]-borrow-num2.v[i];
		if(temp>=0)
		{
			borrow=0;
			ret.v[i]=temp;
		}
		else
		{
			borrow=1;
			ret.v[i]=temp+2;
		}
	}
	for(;i<num1.len;i++)
	{
		temp=ret.v[i]-borrow;
		if(temp>=0)
		{
			borrow=0;
			ret.v[i]=temp;
		}
		else
		{
			borrow=1;
			ret.v[i]=temp+2;
		}
	}
	while(ret.len>=1 && !ret.v[ret.len-1])
		ret.len--;
	return ret;
}
BigNumber div2(BigNumber n)
{
	BigNumber ret;
	ret.len=n.len-1;
	for(int i=0;i<ret.len;i++)
		ret.v[i]=n.v[i+1];
	return ret;
}
void gcd(BigNumber num1,BigNumber num2)
{
	long b=0,i;
	while(num1.len && num2.len)
	{
		if(num1.v[0])
		{
			if(num2.v[0])
			{
				if(isSmaller(num1,num2))
					num2 = minnum(num2,num1);
				else
					num1 = minnum(num1,num2);
			}
			else
				num2=div2(num2);
		}
		else
		{
			if(num2.v[0])
				num1=div2(num1);
			else
			{
				num1=div2(num1);
				num2=div2(num2);
				b++;
			}
		}
	}
	if(num2.len)
		for(i=num2.len-1;i>=0;i--)
			printf("%d",num2.v[i]);
	else
		for(i=num1.len-1;i>=0;i--)
			printf("%d",num1.v[i]);
	while(b--)
		printf("0");
	printf("\n");
}
char str1[maxn],str2[maxn];
int main()
{
	int ca,t;
	BigNumber num1,num2;
	scanf("%d",&t);
	for(int ca = 1; ca <= t; ca ++ )
	{
		scanf("%s%s",str1,str2);
		int len ; 
		len = strlen(str1);
		num1.len= len;
		for(int i=0;i<len;i++)
			num1.v[i]=str1[len-1-i]-'0';
		len = strlen(str2);
		num2.len=len;
		for(int i=0;i<len;i++)
			num2.v[i]=str2[len-1-i]-'0';
		printf("Case #%d: ",ca); 
		gcd(num1,num2);
	}
	return 0;
}

