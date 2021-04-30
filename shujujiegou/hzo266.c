/*************************************************************************
	> File Name: hzo265.c
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Apr 2021 06:44:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node*next;
}Node;
typedef struct Stack{
    Node *head;
}Stack;
Node *initNode(int val){
    Node *n =(Node*)malloc(sizeof(Node));
    n->val = val;
    n->next =NULL;
    return n;
}
void freeNode(Node*p){
    if(p)
        free(p);
    return ;
}
Stack*initStack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->head<F2> =NULL;
    return n;
}

int push(Stack *s,int val){
    if(!s)
    return 0;
    Node *n =initNode(val);
    n->next=s->head;
    s->head=n;

    return 1;
}
int isEmpty(stack*s){
    return 
}

int main(void){
    char str[10005];
    scanf("%s",str);
    stack *s=initStack();
    int i,len=0;
    for(i=0,i<strlen(str);i++){
        if(!isEmpty){
            char c=str[i];
            char t=str[top(s)];
            if(t =='('&& c==')'||t=='['&&c==']'||t=='{'&&c=='}'){
                pop(s);
                if(!isEmpty(s))
                    len=max(len,i-top(s));
                else
                    len=max(len,i+1);
            }else
                push(s,i);
        }else
            push(s,i)
    }
    printf("%d".len);
    freeStack(s);
    return 0;
}
