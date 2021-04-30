/*************************************************************************
	> File Name: hzo268.c
	> Author: 
	> Mail: 
	> Created Time: Tue 27 Apr 2021 06:35:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    int qid;
    struct Node*next;
}Node;

typedef struct Queue{
    Node *head;
    Node *tail;
}Queue;

typedef struct HashTable{
    Node **data;
    int size;

}HashTable;


Node *initNode(int val,int qid){
    Node *n=(Node *)malloc(sizeof(Node));
    n->val =val;
    n->qid =qid;
    n->next =NULL;
    return n;
}

void freeNode(Node *p){
    if(p)
        free(p);
    return ;
}
Queue *initQueue(Queue *q){
    Queue *q=(Queue *)malloc(sizeof(Queue));
    q->head =NULL;
    q->tail=NULL;
    return q;
}

void freeQueue(Queue*q){
    if(!q)
    return ;
    Node *p=q->head,*k;
    while(p){
        k=p;
        p=p->next;
        freeNode(k);
    }
    free(q);
    return ;
}
int push(Queue *q,int val,int qid){
    if(!q)
    return 0;
    Node *n = initNode(val,qid);
    if(!q->tail){
        q->tail=n;
        q->head=n;
        return 1;
    }
    q->tail->next =n;
    q->tail=n;
    return 1;

}
int isEmpty(Queue *q){
    return !q||!q->head;
}
int pop(Queue *q){
    Node *k=q->head;
    int ret =k->val;
    q->head=q->head->next;
    freeNode(k);

    if(!q->head)
        q->tail=NULL;
    return ret;
}
HashTable *initHashTable(int n){
    HashTable *h =(HashTable*)malloc(sizeof(HashTable));
    h->size=2*n;
    h->data=(Node**)calloc(h->size,sizeof(Node*));
    return h;
}

void freeHashTable(HashTable *h){
    if(!h)
        return;
    int i;
    Node *p
    for(i=0;i<h->size;i++){
        p=h->data[i];
        while(p){
            k=p;
            p=p->next;
            freeNode(k);
        }
    }
    free(h->data);
    free(h);
    return;
}

int hash32(int key){
    key=~key+(key<<15);
    key=key^(key>>12);
    key=key+(key<<2);
    key=key^(key>>4);
    key=key*2057;
    key=key^(key>>16);

    return key;
}
int insertHash(HashTable *h,int val,int qid){
    int hash=hash32(val);
    int idx=hash%h->size;
    Node*n=initNode(val.qid);
    n->next=h->data[idx];
    h->data[idx]=n;
    return 1;
}

Node *searchHash(HashTable*h,int val){
    int hash=Hash32(val);
    int idx=hash%h->size;
    Node *p=h->data[idx];
    while(p && p->val!=val){
        p=p->next;
    return p;
    }
}
int main(void){
    int n,m,i,j,temp;
    scanf("%d",&n);
    HashTable *h=initHashTable(1000*n);

    for(i=0;i<n;i++){
        scanf("%d",&m);
        for(j=0;j<m;j++){
            scanf("%d",&tmp);
            insertHash(h,tmp,i);
        }
    }
    char str[10];
    Queue *q=initQueue();
    Node *f;
    Node **arr =(Node**)calloc(n,sizeof(Node*));
    while(~scanf("%s",str)){
        if(!strcmp(str,"STOP"))
            break ;
        else if(!strcmp(str,"ENQUEUE")){
            scan("%d",&tmp);
            f=searchHash(h,tmp);
            if(!f)
                push(q,tmp,-1);
            else{
                if(arr[f->qid]){
                    Node *n =initNode(f->val,f->qid);
                    if(arr[f->qid]==q->tail)
                        q->tail=n;
                    n->next=arr[f->qid]->next;
                    arr[f->qid]->next=n;
                    arr[f->qid]=n;
                }else{
                    push(q,f->val,f->qid);
                    arr[f->qid]=q->tail;

                }
            }
        }else if(!strcmp(str,"DEQUEUE")){
            if(q->head==arr[q->head->qid])
                arr[q->head->qid]
            printf("%d/n",pop(q));
        }
    }




    freeQueue(q);
    freeHashTable(h);
    return 0;
    
}
