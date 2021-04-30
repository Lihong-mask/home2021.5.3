/*************************************************************************
 *
	> File Name: tree.c
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Apr 2021 03:54:04 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct Tree{
    Node *root;
    int len;
}Tree;

Node *initNode(int val){
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void freeNode(Node *p){
    if(!p)
        return;
    free(p);
    return;
}
Tree *initTree(){
    Tree *t =(Tree *)malloc(sizeof(Tree));
    t->root = NULL;
    t->len = 0;
    return t;
}
/*Node *insert(Node *root, int val){
    if(!root){
        Node *n = initNode(val);
        return n;
    }
    if(val > root->val)//插入右子树
        root->right = insert(root->right, val);
    else//插入左子树
        root->left = insert(root->left, val);
    return root;
}*/
void insert(Node **raddr, int val){
    if(!(*raddr)){
        *raddr = initNode(val);
        return ;
    }
    if(val > (*raddr)->val)//插入右子树
        insert(&((*raddr)->right), val);
    else//插入左子树
        insert(&((*raddr)->left), val);
    return ;
}
void insertTree(Tree *t, int val){
    if(!t)
        return ;
    insert(&(t->root), val);
    t->len++;
    return ;
}
void preorderTrav(Node *root){
    if(!root)
        return ;
    printf("%d,",root->val);
    preorderTrav(root->left);
    preorderTrav(root->right);
    return ;
}
void kouorderTrav(Node *root){
    if(!root)
        return ;
    printf("%d",root->val);
    if(!root->left &&!root->right)
        return ;
    printf("(");
    kouorderTrav(root->left);
    printf(",");
    kouorderTrav(root->right);
    printf(")");
    return ;
}
void inorderTrav(Node *root){
    if(!root)
        return ;
    inorderTrav(root->left);
    printf("%d,",root->val);
    inorderTrav(root->right);
    return ;
}

void postorderTrav(Node *root){
    if(!root)
        return ;
    postorderTrav(root->left);
    postorderTrav(root->right);
    printf("%d,",root->val);
    return ;
}
void freeAll(Node *root){
    if(!root)
        return ;
    freeAll(root->left);
    freeAll(root->right);
    freeNode(root);
    return ;

}
void freeTree(Tree *t){
    if(!t)
        return ;
    freeAll(t->root);
    free(t);

    return ;
}
void preorderTree(Tree *t){
    if(!t)
        return ;
    printf("Pre:[");
    preorderTrav(t->root);
    printf("]\n");

}
void inforderTree(Tree *t){
    if(!t)
        return ;
    printf("Pre:[");
    inorderTrav(t->root);
    printf("]\n");
}
void postorderTree(Tree *t){
    if(!t)
        return ;
    printf("Pre:[");
    kouorderTrav(t->root);
    printf("]\n");
}
Node *findNode(Node *root, int val){
    if(!root){
        return NULL;
    }
    if(val == root->val){
        return root;
    }
    if(val > root->val)
        return findNode(root->right,val);
    else
        return findNode(root->left,val);
}

Node *findTree(Tree *t,int val){
    if(!t)
        return NULL;
    return findNode(t->root,val);
}

//实现栈 数据元素类型Node*
typedef struct Stack{
    Node **data;
    int top;
    int size;
}Stack;
Stack *initStack(int n){
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s->data =(Node *)malloc(sizeof(Node*)*n);
    s->top =-1;
    s->size =n;
    return s;
}

void freeStact(Stack *s){
    if(!s)
        return ;
    free(s->data);
    free(s);
    return ;
}
int push(Stack *s,Node *n){
    if(!s)
    return 0;
    if(s->top == s->size-1)
        return 0;
    s->data[++s->top] = n;
    return 1;
}

int isEmpty(Stack *s){
    return !(s && s->top !=1);
}
Node *pop(Stack *s){
    return s->data[s->top--];
}
Node *buildTree(char *str){
    Stack *s =initStack(strlen(str)/2);

    Node *root, *n;
    int flag = 0;
    int num =0;
    while(str[0]){
        switch(str[0]){
            case '(': //遇到左括号，把刚建立的节点压栈
                push(s,n);
                flag=0;
                break;
            case ',':
                flaf=1;
                break;
            case ')':
                root =pop(s);
                break;
            default:
                if(str[0]<'0'||str[0]>'9')
                    break;
                //计算数字是多少？str2int
                num=0;
            while(str[0]>='0' && str[0]<='9'){
                num =num*10 +str[0]- '0';
                str++;
            }
            str--;
            n=initNode(num);
            //根据flag插入栈顶（根）的子树
            if(!isEmpty(s))
            flag ?(s->data[s->top]->right = n):(s->data[s->top]->left=n);
        }
    str++;
    }
    freestack(s);

    return root;
}

int main(){
   /* srand(time(0));

   Tree *t = initTree();
    
  int cnt = 10;
    int want = 0;
    
  while(cnt--){
 //   int val[10] ={78,67,89,45,56,57,43,52,53,23};
   // for(int i = 0; i < 10; i++){ 
    int val = rand() % 100;
        insertTree(t, val);
        if(cnt == 5)
            want = val;
    }
    preorderTree(t);
    
    Node *find = findTree(t,want);
    find?printf("find %d at %p,val =%d\n", want, find ,find->val):printf("%d not found~", want);
    freeTree(t);
*/

    Tree *t =initTree();
    char str[100];
    scanf("%s",str);
    t->root=buildTree(str);

    preorderTree(s);

    return 0;
}
