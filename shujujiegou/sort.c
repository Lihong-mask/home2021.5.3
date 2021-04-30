/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: Sat 17 Apr 2021 04:45:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define swap(a,b){\
    __typeof(a) __tmp=a;\
    a=b;b=__tmp;\
}

#define TEST(arr,n,func,args...){\
    int *brr =(int*)malloc(sizeof(int)*n);\
    memcpy(brr,arr,sizeof(int)*n);\
    func(args);\
    printf("%s=",#func);\
    showArr(brr,n);\
    free(brr);\
}

void insert_sort(int *arr,int n){
    int i,j;
    for(i=1;i<n;i++){
        for(j=i;j>0&& arr[j]<arr[j-1];j--)
            swap(arr[j],arr[j-1]);
    }
    return ;
}

void bubble_sort(int *arr,int n){
    int i,j;
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return ;
}

void select_sort(int *arr,int n){
    int i,j,minidx;
    for(i=0;i<n-1;i++){
        minidx=i;
        for(j=i+1;j<n;j++){
            if(arr[minidx]>arr[j])
                minidx=j;
        }
        swap(arr[i],arr[minidx]);        
    }
    return;
}

void merge_sort(int *arr,int l,int r){
    if(l==r)
        return ;
    int mid=(l+r)>>1;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);

    int *tmp=(int*)malloc(sizeof(int)*(r-l+1));
    int p1 = l,p2=mid+1,k=0;
    while(p1<=mid||p2<=r){
        if(p2>r||(p1<=mid && arr[p1]<arr[p2]))
            tmp[k++]=arr[p1++];
        else
            tmp[k++]=arr[p2++];
    }

    memcpy(arr+l,tmp,sizeof(int)*(r-l+1));
    free(tmp);
    return ;

}
void quick_sort(int *arr,int l, int r){
    if(l>r)
        return;
    int x=l,y=r,z=arr[x];
    while(x<y){
        while(x<y && arr[y]>z)
            y--;
        if(x<y)
            arr[x]=arr[y];
        while(x<y && arr[x]<z)
            x++;
        if(x<y)
            arr[y--]=arr[x];
    }
    arr[x]=z;
    quick_sort(arr,l,x-1);
    quick_sort(arr,x+1,r);

    return;
}

void quick1_sort(int *arr,int l, int r){
    while(l<r){
        int x=l,y=r,z=arr[(l+r)>>1];
        do{
            while(arr[x]<z)
                x++;
            while(arr[y]>z)
                y--;
            if(x<=y){
                swap(arr[x],arr[y]);
                x++;
                y--;
            }
        }while(x<=y);
        quick1_sort(arr,l,y);
        l=x;
    }
    return ;
}

void showArr(int*arr,int len){
    printf("[");
    int i;
    
    for(i=0; i<len;i++){
        i&&printf(",");
        printf("%d",arr[i]);
    }
    printf("]\n");
}
int main(void){
    srand(time(0));
    #define ARRLEN 10
    int arr[ARRLEN];
    int i;
    for(i=0;i<ARRLEN;i++)
        arr[i]=rand()%100;
    showArr(arr,ARRLEN);
    TEST(arr,ARRLEN,insert_sort,brr,ARRLEN);
    TEST(arr,ARRLEN,bubble_sort,brr,ARRLEN);
    TEST(arr,ARRLEN,merge_sort,brr,0,ARRLEN-1);
    TEST(arr,ARRLEN,select_sort,brr,ARRLEN);
    TEST(arr,ARRLEN,quick_sort,brr,0,ARRLEN-1);
    TEST(arr,ARRLEN,quick1_sort,brr,0,ARRLEN-1);
    #undef ARRLEN
    return 0;
}
