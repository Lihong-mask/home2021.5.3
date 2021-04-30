/*************************************************************************
	> File Name: vec.c
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Apr 2021 04:30:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct Vector{
    int *data, size, length;
}Vec;

Vec *init(int n){
    Vec *v =(Vec*)malloc(sizeof(Vec));
    v->data = (int*)malloc(sizeof(int)*n);
    v->size = n;
    v->length = 0;
    return v;
}
void freeVec(Vec *v){
    if(v == NULL)
        return;
    free(v->data);
    free(v);
    return ;
}

int expand(Vec *v){
    if(!v)
        return 0;
    int expsize = v->size;
    int *temp=0;
    while(expsize){
        temp = (int*)realloc(v->data,sizeof(int)*(v->size + expsize));
        if(temp)break;
        expsize /= 2;
    }
    if(!temp)
        return 0;
    v->size += expsize;
    v->data = temp;
    printf("expand %d bytes successfully \n", expsize);
    return 1;
}
int insert(Vec *v, int idx,int val){
    if(!v) return 0;
    if(idx < 0 || idx > v->length){
        return 0;
    }
    if(v->length == v->size){
        if(!expand(v)){
            return 0;
        }
    }
    memcpy(v->data + idx + 1, v->data + idx, sizeof(int)*(v->length - idx));
    v->data[idx] = val;
    v->length++;
    return 1;
}
int erase(Vec *v, int idx){
    if(!v) return 0;
    if(idx < 0 || idx >= v->length){
        return 0;
    } 
    memcpy(v->data + idx,v->data + idx + 1,sizeof(int)*(v->length - idx -1));
    v->length--;
    return 1;
}
void showVec(Vec *v){
    printf("table:{");
    if(v){
        for(int i =0; i < v->length; i++){
            i && printf(",");
            printf("%d,", v->data[i]);
        }
    }
    printf("}\n");
}
int find(Vec *v, int val){
    if(!v) return -1;
    for(int i = 0; i < v->length; i++){
        if(v->data[i] == val){
            return i;
        }
    }
    return -1;
}
int main(void){
    int cnt = 20;
    Vec *v = init(1);
    srand(time(0));
    int fnum;
    while(cnt--){
    
        int opt = rand() % 4;
        int val = rand() % 100;
        int idx =rand() % (v->length + 3) - 1;
        switch(opt){
            case 0:
            case 1:
            case 2:
                printf("insert %d at %d,res = %d\n", val, idx ,insert(v,idx,val));
                break;
            case 3:
                printf("erase at %d, res = %d\n.", idx, erase(v,idx));
                break;
        }
        showVec(v);
        if(cnt == 4) fnum = val;

    }
    printf("find %d at %d\n",fnum, find(v,fnum));
    freeVec(v);
    return 0;
}
