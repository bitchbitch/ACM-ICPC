// File Name: 2.12.c
// Author: cijianzy
// Created Time: 2015年05月15日 星期五 23时22分15秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int  c(int x){
    return x|(0x000000FF);
}

int main(){
    printf("0x%08x",c(0x87654321));
return 0 ;
}
