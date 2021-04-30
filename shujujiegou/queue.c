/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: Sun 25 Apr 2021 04:59:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Queue{
    int *data;
    int size;
    int head,tail;
}Queue;


Queue*initQueue(int n){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->data=(int*)malloc(sizeof(int)*n);
    q->size=n;
    q->head=q->tail =0;
    return q;
}
void freeQueue(Queue*q){
    if(!q)
        return;
    free(q->data);
    free(q);
    return;
}


int expand(Queue*q);

int push(Queue *q,int val){
    if(!q)
    return 0;
    //满队
    if((q->tail+1)%q->size ==q->head){
       if(!expand(q))
           return 0;
    }
    q->tail=(q->tail+1)%q->size;
    q->data[q->tail]=val;
    return 1;
}

int isEmpty(Queue *q){
    return !q||q->head ==q->tail;
    //return !(q && q->head !=q->tail);
}

int pop(Queue*q){
    q->head=(q->head + 1)%q->size;
    return q->data[q->head];
}
void showQueue(Queue *q){
    if(isEmpty(q))
        return ;
    printf("Queue:[");
    int i = q->head;
    for(;i!=q->tail;i=(i+1)%q->size){
        i!=q->head&&printf(",");
        printf("%d", q->data[(i+1)%q->size]);
    }
    printf("]\n");
}

int expand(Queue *q){
    if(!q)
        return 0;
    int expsize =q->size;
    int *tmp;
    while(expsize){
        tmp =(int *)realloc(q->data,sizeof(int)*(q->size+expsize));
        if(tmp)
        break;
        expsize>>=1;
    }
    if(!tmp)
        return 0;
    //把队列中的数据搬运到新家
    int i,j;
    for(i=q->head,j=0;i!=q->tail;i=(i+1)%q->size,j++){
        tmp[j]=q->data[i];
    }
    free(q->data);
    q->data =tmp;
    q->head=0;
    q->tail=j;
    q->size+=expsize;
    printf("expand successfully~,new size is %d\n",q->size);
}

int main(void){
    Queue *q=initQueue(4);
    srand(time(0));

    int cnt =20;
    while(cnt--){
        int val =rand()%100;
        int opt =rand()%4;
        switch(opt){
            case 0:
            case 1:
            case 2:
            printf("push%d,res=%s\n",val,push(q,val)?"SUC":"ERR");
            break;
            case 3:
            isEmpty(q)?printf("pop nothing~\n"):printf("pop %d\n",pop(q));
            break;
        }
        showQueue(q);
    }
    

    freeQueue(q);
    return 0;
}
