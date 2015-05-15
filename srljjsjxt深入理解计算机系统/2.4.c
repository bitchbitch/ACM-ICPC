// File Name: 2.4.c
// Author: cijianzy
// Created Time: 2015年05月14日 星期四 14时18分48秒

#include<stdio.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start,int len){
    int i ; 
    for(i = 0 ;i < len; i++){
        printf("%.2x",start[i]);
    }
    printf("\n");
}
void show_int(int x){
    show_bytes((byte_pointer)&x,sizeof(int));
}
void show_float(float x){
    show_bytes((byte_pointer)&x,sizeof(float));
}
void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main(){
    const char *s = "abcdef";
    show_bytes((byte_pointer)s,strlen(s))t
    show_int(12345);    
return 0 ;
}
