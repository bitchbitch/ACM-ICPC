#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
const int N=100010;
struct tree{
	int left,right,numcol;
	bool cover;
}tt[N*4];
int len,numcolour,numop,x,y;
void build_tree(int lp,int rp,int pos){
	tt[pos].left=lp;
	tt[pos].right=rp;
	tt[pos].numcol=(1<<1);
	tt[pos].cover=true;
	if(lp==rp)return;
	int mid=(lp+rp)/2;
	build_tree(lp,mid,pos*2);
	build_tree(mid+1,rp,pos*2+1);
}
void add(int lp,int rp,int id,int pos){
	if(lp<=tt[pos].left&&rp>=tt[pos].right){
		tt[pos].cover=true;
		tt[pos].numcol=(1<<id);
		return;
	}
	if(tt[pos].cover){
		tt[pos*2].cover=true;
		tt[pos*2+1].cover=true;
		tt[pos*2].numcol=tt[pos].numcol;
		tt[pos*2+1].numcol=tt[pos].numcol;
		tt[pos].cover=false;
	}
	int mid=(tt[pos].left+tt[pos].right)/2;
	if(lp<=mid)
		add(lp,rp,id,pos*2);
	if(rp>mid)
		add(lp,rp,id,pos*2+1);
	tt[pos].numcol=tt[pos*2].numcol|tt[pos*2+1].numcol;
}
int query(int lp,int rp,int pos){
	if(tt[pos].left==lp&&tt[pos].right==rp){
		return tt[pos].numcol;
	}
	if(tt[pos].cover){
		tt[2*pos].cover=true;
		tt[2*pos+1].cover=true;
		tt[2*pos].numcol=tt[pos].numcol;
		tt[2*pos+1].numcol=tt[pos].numcol;
		tt[pos].cover=false;
	}
	int mid=(tt[pos].left+tt[pos].right)/2;
	if(lp>mid)
		return query(lp,rp,pos*2+1);
	else if(rp<=mid)
		return query(lp,rp,pos*2);
	else
		return query(lp,mid,pos*2)|query(mid+1,rp,pos*2+1);
}
int fenjie(int x){
	int ans=0;
	while(x){
	  if(x%2)
		  ans++;
	  x/=2;
	}
	return ans;
}
int main(){
	freopen("数颜色.in","r",stdin);
	freopen("数颜色1.out","w",stdout);
	clock_t be,en;
	be = clock();
	int num ;
    scanf("%d",&num);
	while(num--){
	  scanf("%d%d%d",&len,&numcolour,&numop);
	  build_tree(1,len,1);
	  char ss[2];
	  int id;
	  while(numop--){
	    scanf("%s",ss);
		if(ss[0]=='C'){
		  scanf("%d%d%d",&x,&y,&id);
		  if(x>y)
			  swap(x,y);
		  add(x,y,id,1);
		}
		else{
		  scanf("%d%d",&x,&y);
		  if(x>y)
			  swap(x,y);
		  int sum=query(x,y,1);
		  int total=fenjie(sum);
		  printf("%d\n",total);
		}
	  }
	}
	en = clock();
	//printf("%lf",(en-be)*1.0/CLOCKS_PER_SEC);
	return 0;
}

