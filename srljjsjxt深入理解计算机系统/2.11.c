// File Name: 2.11.c
// Author: cijianzy
// Created Time: 2015年05月15日 星期五 23时09分00秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void inplace_swap(int *x,int *y){
    *y = *x ^ *y;
    *x = *y ^ *x; 
    *y = *y ^ *x; 
}
void reverse_array(int a[],int cnt){
    int first ,last; 
    for(first = 0 , last = cnt - 1; first < last/* 必须是小于*/; first ++,last--){
        inplace_swap(&a[first],&a[last]);
    }
}
int main(){
    int b[]={1,2,3,4,1};
    reverse_array(b,5);
    int i ; 
    for(i = 0 ;i < 5;i ++)
        printf("%d ",b[i]);

return 0 ;
}
