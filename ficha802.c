#include <stdlib.h>
#include <stdio.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r != NULL) {
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

typedef LInt Stack;

void initStack(Stack * s) {
    *s = NULL;
}

int SisEmpty(Stack s) {
    return (s == NULL);
}

void push(Stack *s, int x) {
    Stack a = *s;
    *s = malloc(sizeof(struct slist));
    (*s)->valor = x;
    (*s)->prox = a;
}

void pop (Stack *s, int *x) {
if(!SisEmpty(*s)) {
    *x = (*s)->valor;
    *s = (*s)->prox;
}
}

void top (Stack s, int *x) {
    if(!SisEmpty(s)) *x = s->valor;
}

typedef struct {
    LInt inicio;
    LInt fim;
} Queue;

void initQueue (Queue *q) {
    q->inicio = NULL;
    q->fim == NULL;
}

int QisEmpty (Queue q) {
    return (q.inicio == NULL);    
}

void enqueue (Queue *q, int x) {

    LInt new = malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;

    if (QisEmpty(*q)) {
        q->inicio = q->fim = new;
    }
    else{
        q->fim->prox = new;
        q->fim = new;
    }
}

int dequeue (Queue *q, int *x) {
    if (QisEmpty(*q))
        return 1;
    else {
        LInt tmp = q->inicio->prox;
        *x = q->inicio->valor;
        free(q->inicio);
        q->inicio = tmp;
    }
    return 0;
}

int front (Queue q, int *x) {
    if (QisEmpty(q))
        return 1;
    else {
        *x = q.inicio->valor;
    }
    return 0;
}

typedef LInt QueueC;

void initQueueC (QueueC *qc) {
    *qc = NULL;
}

int QisEmptyC (QueueC qc) {
    return (qc == NULL);    
}

void enqueue (QueueC *qc, int x) {
    LInt new = malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;

    if (QisEmptyC(*qc)) {
        new->prox = (*qc)->prox;
        (*qc)->prox = new;
        *qc = new;
    }
    
}


int main() {

    // Stack s;
    // initStack(&s);
    // printf("SisEmpty: %d\n", SisEmpty(s));
    // push(&s, 2);
    // push(&s, 4);
    // printf("SisEmpty: %d\n", SisEmpty(s));
    // int a;
    // top(s, &a);
    // printf("a: %d\n", a);

    //Queue q;
    //initQueue(&q);
    //printf("QisEmpty: %d\n", QisEmpty(q));
    //enqueue(&q, 2);
    //enqueue(&q, 4);
    //enqueue(&q, 6);
    //printf("QisEmpty: %d\n", QisEmpty(q));
    //int x;
    //front(q, &x);
    //printf("front: %d\n", x);
    //int y;
    //dequeue(&q, &y);
    //printf("dequeue: %d\n", y);
    //int z;
    //dequeue(&q, &z);
    //printf("dequeue: %d\n", z);
    //int p;
    //dequeue(&q, &p);
    //printf("dequeue: %d\n", p);
    //printf("QisEmpty: %d\n", QisEmpty(q));

    QueueC qc;
    initQueueC(&qc);
    printf("QisEmptyC: %d\n", QisEmptyC(qc));


    return 0;
}