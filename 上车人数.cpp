#include <stdio.h>
struct node{
  int x, y ;
}a[1000],b[1000],c[1000];
int main(){
  int s, n,m,w; 
  scanf("%d %d %d %d",&s,&n,&m,&w);
  a[1].x = 1;
  a[1].y = 0;
  a[2].x = 0; 
  a[2].y = 1;
  c[2].x = 1; 
  c[2].y = 0;
  for(int i = 3;i <= n;i ++)
  {
    a[i].x = a[i-1].x + a[i-2].x;
    a[i].y = a[i-1].y + a[i-2].y;
	b[i].x = a[i-1].x ;
	b[i].y = a[i-1].y ;
	c[i].x = c[i-1].x + a[i].x - b[i].x;
	c[i].y = c[i-1].y + a[i].y - b[i].y;
  }
  int k = (m - b[n].x*s)/b[n].y;
  printf("%d",c[w].x*s + c[w].y*k);
return 0;
}
