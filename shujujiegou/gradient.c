/*************************************************************************
	> File Name: gradient.c
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Apr 2021 07:56:06 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//计算f(x)=ax^2+bx+c的极值
double gradientDesc(double a,double b,double c,int cnt){
    double l =0.1;
    double x=rand()/(double)RAND_MAX*20-10;
    int i;
    for(i=0;i<cnt;i++){
        //f(x)对x求导f'(x)=2ax+b
        double gradient=2*a*x+b;
        if(a>0)
            x=x-gradient*l;
        else
            x=x+gradient*l;
        //计算f(x)
        double fx =a*x*x+b*x+c;
        printf("i=%d x=%lf fx=%lf gradient=%lf\n",i,x,fx,gradient);
    }
    return x;
}
int main(void){
    srand(time(0));
    int a=rand()%20-10;
    int b=rand()%20-10;
    int c=rand()%20-10;

    a=a==0?1:a;
    printf("f(x)=%dx^2+%dx+%d\n",a,b,c);
    gradientDesc(a,b,c,100);
    return 0;
}
