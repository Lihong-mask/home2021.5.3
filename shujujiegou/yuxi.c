#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
    int size,length;
    int *data;

} Vector;

void init(Vector *vector,int size) {
    vector->size =size;
    vector->length =0;
    vector->data =(int*)malloc(sizeof(int)*size);

}

void expand(Vector *vector) {
    int *olddata =vector->data;
    vector->size=vector->size*2;
    for(int i =0;i<vector->length;i++){
    vector->data[i] = olddata[i];
    }
    printf("%s\n","expand");
    free(olddata);
}

int insert(Vector *vector ,int loc,int value) {
    if(loc<0||loc>vector->length)
    {
         printf("%s\n", "fail");
        return 0;
    }
    if(vector->size <= vector->length)
    {
        expand(vector);
    }
    for(int i=vector->length-1;i>=loc;i--)
    {
        vector->data[i] =vector->data[i-1];
    }
    vector->data[loc] =value;
    vector->length++;
   printf("%s\n", "success");
    return 1;

}


void clear(Vector *vector) {
    free(vector->data);
    free(vector);

}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 5);
    int n, p, q;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d\n", &p, &q);
        insert(a, p, q);
    }
    

    return 0;
}