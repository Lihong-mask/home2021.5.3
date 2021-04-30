/*************************************************************************
	> File Name: search.c
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Apr 2021 06:14:26 PM CST
 ************************************************************************/

#include<stdio.h>

int binary_search(int *arr,int n,int x){
    int head=0,tail=n-1,mid;
    while(head<=tail){
        mid=(head+tail);
        if(arr[mid]==x)
            return mid;
          arr[mid]>x?(head =mid+1):(tail=mid-1);
    }
    return -1;
}
//0000000000001111111111111
int binary_search_first1(int *arr,int n){
    int head = 0,tail =n,mid;
    while(head<tail){
        mid =(head+tail)>>1;
        if(arr[mid]==1)
            tail =mid;
        else
            head=mid+1;
    }
    return head==n?-1:head;
}
//111111111110000000000000
int binary_search_last1(int *arr,int n){
    int head = -1,tail =n-1,mid;
    while(head<tail){
        mid =(head+tail+1)>>1;
        if(arr[mid]==1)
            head =mid;
        else
            tail=mid-1;
    }
    return head;
}
int main(){
    srand(time(0));

    #define N 10
    int arr[N];
    int i;
    for()
}
