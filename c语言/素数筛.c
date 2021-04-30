/*************************************************************************
	> File Name: 素数筛.c
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Apr 2021 11:34:42 AM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N  100
int prime[MAX_N + 5];
void init(){
    for(int i = 2; i <= MAX_N; i++){
        if(prime[i])continue;
        prime[++prime[0]] = i;
        for(int j = 2 * i; j < MAX_N; j += i){
            prime[j] = 1;
        }
    }
    return ;
}

int main(){
    init();
    for(int i = 1; i <= prime[0]; i++){
        printf("%d\n", prime[i]);
    }
    return 0;
}
