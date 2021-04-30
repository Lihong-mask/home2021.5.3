/*************************************************************************
	> File Name: quickFind.c
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Apr 2021 02:24:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct UnionSet{
    int*father
    int *len;
    int size;
}UnionSet;

UnionSet *initSet(int n){
    UnionSet *u =(UnionSet*)malloc(sizeof(UnionSet));
    u->color =(int*)malloc(sizeof(int)*(n+1));
    u->len =(int*)malloc(sizeof(int)*(n+1));
    u->size=n+1;
    int i;
    for(i=0;i<u->size;i++)
        u->color[i]=i;
    return u;

}

void freeSet(UnionSet *u){
    if(!u)
        return;
    free(u->color);
    free(u);
    return;

}
int find(UnionSet *u,int idx){
    if(u->father[idx]==idx)
        return find(u,u->father[idx]);
}
int merge(UnionSet *u,int a,int b){
    int fa = find(u,a),fb=find(u,b);
    if(fa==fb)
    return 0;
    if(u->len[fa]>u->len[fb]){
        u->father[fb]=fa;
        u->len[fa]+=u->len[fb];
    }else{
        u->father[fa]=fb;
        u->len[fb]+=u->len[fa];
    }
    return 1;
}
int main(){
    int n, m, i;
    scanf("%d%d",&n,&m);
    UnionSet *u=initSet(n);

    for(i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        switch(a){
            case 1:
            merge(u,b,c);
            break;
            case 2:
            printf("%s\n",find(u,b)=find(u,c)?"Yes":"No");
            break;
        }
    }
    freeSet(u);

    return 0;
}
