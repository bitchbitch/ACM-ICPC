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
using namespace std;
#define LL long long
char s[1000010];
int l,a,b,f,i,c;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output1.txt","w",stdout);

    while (gets(s))
    {
        int l=strlen(s);
        if (l % 2 || s[l-1]=='(')
        {
            puts("None");
            continue;
        }
        a=0,b=0,f=1,c=0;
        for (i=0;i<l;i++)
        {
            if (s[i]=='(')
            {
                c+=b;
                b=0;
                a++;continue;
            }
            if (s[i]==')')
            {
                if (a==0 && b==0 && c==0)
                {
                    puts("None");
                    f=0;
                    break;    
                }
                else if (a!=0) a--;
                else if (b!=0) b--;
                else c--;
                continue;
            }
            if (s[i]=='?')
            {
                if (a>0) b++;
                else c++;
                continue;
            }
        }
        if (f==0) continue;
        if (a>b) puts("None");
        else
        {
            if ((b-a) %2!=c%2) puts("None");
            else
            {
                if (b==0) if (c>2)
                    puts("Many");
                else puts("Unique");
                else
                {
                if (c-b>0)
                {
                if (c-b>=2)
                    puts("Many");
                        else puts("Unique");
                }
                else if(b-c>=2)
                    puts("Many");
                else puts("Unique");
                }
            }
            /*if (b % 2==1) puts("None");
            else if (b==0) puts("Unique");
            else puts("Many");*/
        }
    }
    return 0;
}


