#include<stdio.h>
#include<math.h>
#include<limits.h>
#define M 10010
#define LL long long
LL r[M];
int main()
{
//        freopen("C:\\Users\\Devin\\Desktop\\cin.txt","r",stdin);
//        freopen("C:\\Users\\Devin\\Desktop\\cout.cpp","w",stdout);
        int t;
        scanf("%d",&t);
        while(t--)
        {
                int N,F;
                scanf("%d %d",&N,&F);
                F++;
                LL maxx=LONG_LONG_MIN;
                for(int i=0;i<N;++i)
                {
                        scanf("%lld",&r[i]);
                        r[i]*=r[i];
                        maxx=r[i]>maxx?r[i]:maxx;
                }
                double hi=maxx*1.0*M_PI,lo=0.0,mi;
                while(hi-lo>1e-4)
                {
                        mi=(lo+hi)/2.0;
                        int cnt=0;
                        for(int i=0;i<N&&cnt<=F;++i)
                        {
                                cnt+=(int)(floor)(r[i]*1.0*M_PI/mi);
                        }
                        if(cnt>=F) lo=mi;
                        else hi=mi;
                }
                printf("%.4lf\n",lo);
        }
        return 0;
}
