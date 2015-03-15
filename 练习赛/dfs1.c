// File Name: dfs1.c
// Author: darkdream
// Created Time: 2013年03月12日 星期二 19时23分30秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h> 
int map[3][15][15];
int visit[3][15][15];
struct node 
{
  int x,y,z,step;
};
struct node list[500];
int xdd[] = {1,-1,0,0};
int ydd[] = {0,0,1,-1};
int main(){

    freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int k;
   scanf("%d",&k);
   while(k--)
   {   memset(map,0,sizeof(map));
       memset(visit,0,sizeof(visit));
	   memset(list,0,sizeof(list));
       int n , m , t , x, y ,z, x1,y1 ,z1;
       char a[15] ; 
       scanf("%d %d %d",&n,&m,&t);
       getchar();
       int now ,last, ans = 0 ;
       for(int i = 1;i <= n ; i ++)
       {    scanf("%s",a);
           for(int j = 0 ;j < strlen(a); j++)
           {
             if(a[j] == 'P')
             {
            
               x1 = i;
               y1 = j+1;
               z1= 1;
               map[1][i][j+1] = 1;
             }
             else if(a[j] == '.')
             {
              map[1][i][j+1] = 1;
             }
             else if(a[j] == '#')
             {
              map[1][i][j+1] = 2;
             }


           }
           
       
       }
       getchar();
       for(int i =1;i <= n; i++)
       {
          scanf("%s",a);
          for(int j = 0 ;j <strlen(a); j++) 
           {
             if(a[j] == 'P')
             {
               x1 = i;
               y1 = j+1;
               z1 = 2;
               map[2][i][j+1] = 1; 
             }
             else if(a[j] == '.')
             {
              map[2][i][j+1] = 1;
             }
             else if(a[j] == '#')
             {
              map[2][i][j+1] = 2;
             }


           }
       }
       list[1].x = 1;
       list[1].y = 1;
       list[1].z = 1;
       list[1].step =0;
       visit[1][1][1] = 1;
       map[1][1][1] = 1;
	   now = 1; 
       last =1;
	/*for(int niu =1; niu <=2; niu ++)
     { for(int i = 1;i <= n ;i ++)
         { for(int j = 1; j <= m ;j ++)
               printf("%d ",map[niu][i][j]);
               printf("\n");
         }
         printf("\n");

     }*/
     while(now <= last)
       {
           if(list[now].x == x1 && list[now].y == y1 && list[now].z == z1)
             {
               ans = 1;
               break;
             }
           for(int i = 0 ;i < 4; i ++)
           {
              int xx, yy ,zz = list[now].z;
              xx = list[now].x + xdd[i];
              yy = list[now].y + ydd[i];
              if(map[list[now].z][xx][yy] == 2)
                { 
                    visit[list[now].z][xx][yy] = 1;
			    	if(list[now].z == 1)
				     zz ++;
                  else
                      zz--;
				  //if(map[zz][xx][yy] == 2)
					//  continue;
                }
              else
                  zz = list[now].z;
              if(map[zz][xx][yy] != 0 && !visit[zz][xx][yy])
              {
               //printf("%d %d %d\n",zz,xx,yy);
                visit[zz][xx][yy] = 1;
                list[++last].z = zz;
                list[last].x = xx;
                list[last].y = yy;
                list[last].step = list[now].step+1;
              }
              
           }
           now ++;
           
       
       }
        //printf("%d %d\n",ans ,list[now].step);
           if(ans == 1 && list[now].step <=  t)
           printf("YES\n");
       else
           printf("NO\n");
   }
return 0 ;
}
