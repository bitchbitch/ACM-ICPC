#include<stdio.h>
int main()
{
        double len;
        while(~scanf("%lf",&len),len!=0.0)
        {
                int ans=0;
                double val=0.0;
                for(int i=2;1;++i)
                {
                        if((val+1.0/i)-len<1e-9)
                                val+=1.0/i,ans++;
                        else break;
                }
                printf("%d card(s)\n",ans);
        }
        return 0;
}

