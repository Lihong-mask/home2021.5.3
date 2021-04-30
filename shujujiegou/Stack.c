/*************************************************************************
	> File Name: Stack.c
	> Author: 
	> Mail: 
	> Created Time: Sun 25 Apr 2021 11:50:22 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Stack{
    int *data;
    int top;
    int size;
}Stack;

int expand(Stack *s);
Stack *initStack(int n){
    Stack *s =(Stack*)malloc(sizeof(Stack));
    s->data=(int*)malloc(sizeof(int)*n);
    s->top =-1;
    s->size=n;
    return s;
}
//指针地址
void freeStack(Stack **saddr){
    if(!(*saddr))
        return;
    free((*saddr)->data);
    free(*saddr);
    *saddr=NULL;
    return;
}

int push(Stack *s,int val){
    if(!s)
        return 0;
    if(s->top==s->size-1){
       if(!expand(s)) return 0;

    }
    s->data[++s->top]=val;
    return 1;
}
int isEmpty(Stack *s){
    return !s||s->top ==-1;
    //return !(s && s->top !=1);
}

//出栈
int pop(Stack *s){
    return s->data[s->top--];
}

void showStack(Stack *s){
    if(isEmpty(s))
        return ;
    printf("Stack:[");
    int i;
    for(i=0;i<=s->top;i++){
        i&&printf(",");
        printf("%d",s->data[i]);
    }
    printf("]\n");
}

int expand(Stack *s){
    if(!s)
    return 0;
    int expsize=s->size;
    int*tmp;
    while(expsize){
        tmp=(int*)realloc(s->data,sizeof(int)*(s->size+expsize));
        if(tmp)
        break;
        expsize>>=1;
    }
    if(!tmp)
        return 0;
    s->data=tmp;
    s->size+=expsize;
    printf("expand successfully~,new size is %d\n",s->size);
    return 1;
}

int main(){
    Stack *s=initStack(5);
    srand(time(0));
    int cnt =20;
    while(cnt--){
        int val=rand()%100;
        int opt=rand()%4;

        switch(opt){
            case 0:
            case 1:
            case 2:
            printf("push %d,res=%s\n",val,push(s,val)?"SUC":"ERR");
            break;
            case 3:
            isEmpty(s)?printf("pop noting~\n"):printf("pop %d\n",pop(s));
            break;
        }
        showStack(s);
    }
    
    return 0;
}
