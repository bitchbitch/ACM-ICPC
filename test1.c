#include <stdio.h>
#include <string.h>
#include <math.h>
int map[51][51];
int visit[51][51];
char str[51];
struct node
{
  int x, y ,step;
}list[2000];
int xdd[]={0,0,-1,1};
int ydd[]={-1,1,0,0};
int main()
{
   int t ;
   scanf("%d",&t);
   while(t--)
   {
     
     int n, m;
     memset(map,0,sizeof(map));
     memset(str,0,sizeof(str));
     memset(list,0,sizeof(list));
     scanf("%d %d",&n,&m);
     int bx,by,sbx,sby,ex,ey;
     int k = 0;
     for(int i = 1;i <= n; i++)
     {
       scanf("%s",&str[1]);
        
         for(int j = 1; j<= m;j ++)
         {
           if(str[j] == 'D')
           {
              ex = i ;
              ey = j;
             
           }
         }
         for(int j = 1; j<= m;j ++)
         {
           if(str[j] == 'S')
           {
              bx = i ;
              by = j ;
              str[j] = '.' ;
           }
         }
        
         for(int j = 1; j<= m;j ++)
         {
           if(str[i][j] == '*')
           {
              k++;
              list[k].x = i;
              list[k].y = j;
              list[k].step  = 1;
              map[i][j] = 1;
              
           }
         }
        
        
     }
     
      
     int low  = 1,high = k;
     int ok = 0 ;
     while(low <= high)
     {
        for(int i = 0 ;i <= 3;i ++)
        {
          int tx = list[low].x + xdd[i];
          int ty = list[low].y + ydd[i];
          if(map[tx][ty] == 0  && str[tx][ty] == '.')
          {
             high ++;
             list[high].x = tx;
             list[high].y = ty;
             list[high].step = list[low].step + 1;
             map[tx][ty] = list[high].step;
             
          }
        }
        low++;
     }
 
  /*   for(int i = 1;i <= n;i ++)
     {
         for(int j = 1; j <= n;j ++)
         {
           printf("%d ",map[i][j]);
         }
         printf("\n");
     }*/
 
     memset(list,0,sizeof(list));
     list[1].x = bx;
     list[1].y = by;
     list[1].step  = 1;
     low = 1;  
     high = 1;
     visit[bx][by] = 1;
     memset(visit,0,sizeof(visit));
     map[ex][ey]  = 1000;
     str[ex][ey]  = '.';
     while(low <= high)
     {
         if(list[low].x == ex && list[low].y == ey)
         {
            ok = 1;
            break;
         }
         for(int i = 0 ;i <= 3; i ++)
         {
           int tx = list[low].x + xdd[i];
           int ty = list[low].y + ydd[i];
           int tstep = list[low].step +1;
           if(visit[tx][ty] == 0  && str[tx][ty] == '.')
           {
              if(tstep < map[tx][ty] || map[tx][ty] == 0)
              {
               high ++;
               list[high].x = tx;
               list[high].y = ty;
               list[high].step = tstep;
               visit[tx][ty]  = 1 ;           
              }
           }
         }
       low ++;
     }
      
      if(ok )
          printf("%d\n",list[low].step-1);
      else
          printf("NO\n");
 
   }
   return 0 ;
}
