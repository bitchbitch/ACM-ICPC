#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
 
struct node{
    int a,b,color;
}s[400000];
int h[60];
int Build(int x,int y,int num){
    s[num].a=x; s[num].b=y;
    s[num].color=1;
    if(x==y)
        return 0;
    else{
        Build(x,(x+y)/2,num+num);
        Build((x+y)/2+1,y,num+num+1);
    }
}
 
int modify(int x,int y,int num,int color){
    if(x==s[num].a&&y==s[num].b){
        s[num].color=color;
        return 0;
    }
    if(s[num].color==color)
        return 0;
    if(s[num].color>0){
        s[num+num].color=s[num+num+1].color=s[num].color;
        s[num].color=0;
    }   
    if(y<=(s[num].a+s[num].b)/2)
        modify(x,y,num+num,color);
    else if(x>(s[num].a+s[num].b)/2)
        modify(x,y,num+num+1,color);
    else{
        modify(x,(s[num].a+s[num].b)/2,num+num,color);
        modify((s[num].a+s[num].b)/2+1,y,num+num+1,color);
    }
}
 
int getsum(int x,int y,int num){
    if(s[num].color>0){
        h[s[num].color]=1;
        return 0;
    }
    else{
        if(y<=(s[num].a+s[num].b)/2)
            getsum(x,y,num+num);
        else if(x>(s[num].a+s[num].b)/2)
            getsum(x,y,num+num+1);
        else{
            getsum(x,(s[num].a+s[num].b)/2,num+num);
            getsum((s[num].a+s[num].b)/2+1,y,num+num+1);
        }
    }
}
 
int main(){
    int l,t,cas,i,j,sum;
    int x,y,color;
    char c;
    freopen("数颜色.in","r",stdin);
	 scanf("%d %d %d",&l,&t,&cas);
        memset(h,0,sizeof(h));
        Build(1,l,1);
        for(j=1;j<=cas;j++){
            sum=0;
            cin>>c;
            if('P'==c){
                scanf("%d %d",&x,&y);
                getsum(x,y,1);
                for(i=1;i<=t;i++)
                    cout<<h[i];
                cout<<endl;
                for(i=1;i<=t;i++)
                    sum+=h[i];
                printf("%d\n",sum);
                memset(h,0,sizeof(h));
            }
            else if('C'==c){
                scanf("%d %d %d",&x,&y,&color);
                modify(x,y,1,color);
            }
        }
    return 0;
}
