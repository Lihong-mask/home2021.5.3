/*************************************************************************
	> File Name: heap.c
	> Author: 
	> Mail: 
	> Created Time: Sat 17 Apr 2021 02:21:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define swap(a,b) {\
    __typeof(a) __tmp=a;\
    a=b;b=__tmp;\
 }
typedef struct Heap{
    int *data;
    int size;
    int len;
}Heap;

Heap *initHeap(int n){
    Heap *h =(Heap *)malloc(sizeof(Heap));
    h->data =(int*)malloc(sizeof(int)*n);
   h-> size =n;
   h->len =0;
    return h;
}
void freeHeap(Heap *a){
    if(!a)
        return;
    free(a->data);
    free(a);
    return ;
}
int push(Heap *h,int val){
    if(!h)
        return 0;
    if(h->size == h->len)
        return 0;
    h->data[h->len] = val;
    h->len++;

    //调整新插入的数据位置
    int idx =h->len;
    while(idx && h->data[idx]>h->data[(idx-1)/2]){
        swap(h->data[idx],h->data[(idx-1)/2]);
        idx = (idx-1)/2;
    }
    h->len++;
    return 1;
}

void downAdj(int *arr,int idx,int len){
    while(idx*2+1 < len){
        int tmp=idx,l=idx*2+1,r=idx*2+2;
         //如果左孩子比父节点大，tmp记录左孩子的位置
         if(arr[l]>arr[tmp])
             tmp=l;
        //如果右孩子比父节点大，tmp记录右孩子的位置
        if(r<len && arr[r]>arr[tmp])
            tmp=r;
    
        //如果父节点就是最大的，堆已经平衡了
        if(tmp == idx)
            break;
        //交换父节点和最大孩子的位置
        swap(arr[tmp],arr[idx]);
        //记录父节点当前的位置
        idx=tmp;
    }
    return ;
}
int isEmpty(Heap *h){
    return !h||!h->len;
}
int pop(Heap *h){
    int ret =h->data[0];
    h->data[0]=h->data[h->len-1];
    h->len--;
    downAdj(h->data,0,h->len);
    return ret;
}

void showHeap(Heap *h){
    printf("heap:[");
    for(int i= 0;i<h->len; i++){
        i&&printf(",");
        printf("%d",h->data[i]);
    }
    printf("]\n");
    return ;
}
int main(void){
    srand(time(0));
    #define HEAPLEN 10

    Heap *h=initHeap(HEAPLEN);
    int cnt = HEAPLEN;
    while(cnt--){
        int val =rand()%100;
        push(h,val);
    }
    showHeap(h);
    printf("pop:[");
    while(!isEmpty(h))
        printf("%d",pop(h));
    printf("]\n");

    freeHeap(h);
    #undef HEAPLEN
    return 0;
}

