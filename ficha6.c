#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//1
typedef struct staticStack
{
    int sp;
    int values[MAX];
} STACK, *SStack;

void SinitStack(SStack s)
{
    s->sp = -1;
}

int SisEmpty(SStack s)
{
    if (s->sp == -1)
        return 0;
    else
        return 1;
}

int Spush(SStack s, int x)
{
    if (s->sp == MAX)
        return 1;

    s->sp++;
    s->values[s->sp] = x;

    return 0;
}

int Spop(SStack s, int *x)
{

    if (SisEmpty(s) == 0)
        return 1;

    *x = s->values[s->sp];
    s->sp--;

    return 0;
}

int Stop(SStack s, int *x)
{

    if (SisEmpty(s) == 0)
        return 1;

    *x = s->values[s->sp];

    return 0;
}

//2
typedef struct staticQueue {
    int front;
    int length;
    int values [MAX];
} QUEUE, *SQueue;

void SinitQueue (SQueue q) {
    q->length = 0;
    q->front = 0;
}

int SisEmptyQ (SQueue q) {
    if (q->length == 0)
        return 0;

    return 1;
}

int Senqueue (SQueue q, int x) {
    if (q->length == MAX)
        return 1;

    q->values[q->length] = x;
    q->length++;

    return 0;
}

int Sdequeue (SQueue q, int *x) {
    if (SisEmptyQ(q) == 0)
        return 1;

    *x = q->values[q->front];
    q->front++;
    q->length--;

    return 0;
}

int Sfront (SQueue q, int *x) {
    if (SisEmptyQ(q) == 0)
        return 1;

    *x = q->values[q->front];

    return 0;
}
//3

typedef struct dinStack {
    int size;
    int sp;
    int *values;
} *DStack;

void dshow(DStack d) {

    if (d->sp != -1) {
        for (int i = 0; i <= d->sp; i++) {
            printf("d->values[%d]: %d\n", i, d->values[i]);
        }
    }  
}

void dinitStack(DStack d)
{
    d->size = 2;
    d->values = malloc(d->size * sizeof(int));
    d->sp = -1;
}


int disEmpty(DStack d)
{
    if (d->sp == -1)
        return 0;
    else
        return 1;
}


void dpush(DStack d, int x)
{
    if (d->sp == d->size) {
        d->size = d->size * 2;
        d->values = realloc(d->values, d->size * sizeof(int));
    }
        
    d->sp++;
    d->values[d->sp] = x;
}


int dpop(DStack d, int *x)
{
    if (disEmpty(d) == 0)
        return 1;

    *x = d->values[d->sp];
    d->sp--;

    return 0;
}

int dtop(DStack d, int *x)
{

    if (disEmpty(d) == 0)
        return 1;

    *x = d->values[d->sp];

    return 0;
}

typedef struct dinQueue {
    int size;
    int front;
    int length;
    int *values;
} *DQueue;

void qshow(DQueue q) {
    for (int i = 0; i < q->length; i++) {
        printf("q->values[%d]: %d\n", i, q->values[i]);
    }
}  

void DinitQueue (DQueue q) {
    q->size = 2;
    q->front = 0;
    q->length = 0;
    q->values = malloc(q->size * sizeof(int));
}

int DisEmptyQ (DQueue q) {
    if (q->length == 0)
        return 0;

    return 1;
}

void Denqueue (DQueue q, int x) {
    if (q->length == q->size) {
        q->size = q->size * 2;
        //q->values = malloc(q->size * sizeof(int)); //malloc clears queue, lets use realoc
        q->values = realloc(q->values, q->size * sizeof(int));
    }

    q->values[q->length] = x;
    q->length++;
}

int Ddequeue (DQueue q, int *x) {
    if (DisEmptyQ(q) == 0)
        return 1;

    *x = q->values[q->front];
    q->front++;
    q->length--;

    return 0;
}

int Dfront (DQueue q, int *x) {
    if (DisEmptyQ(q) == 0)
        return 1;

    *x = q->values[q->front];

    return 0;
}

int main(int argc, char *argv[])
{
    /*
    STACK s;
    SinitStack(&s);

    int x;
    int y;

    Spush(&s, 2);
    Spush(&s, 4);
    Spop(&s, &x);
    Stop(&s, &y);

    printf("x: %d\n", x);
    printf("y: %d\n", y);


    QUEUE q;
    SinitQueue(&q);

    int k;
    int l;
    int h;
    
    Senqueue(&q, 6);
    Senqueue(&q, 8);
    Senqueue(&q, 10);
    Sdequeue(&q, &k);
    Sdequeue(&q, &h);
    Sfront(&q, &l);

    printf("k: %d\n", k);
    printf("h: %d\n", h);
    printf("l: %d\n", l);

    
    struct dinStack d;
    dinitStack(&d);

    dpush(&d, 4);
    dpush(&d, 8);
    dpush(&d, 10);
    dpush(&d, 12);
    int a;
    dtop(&d, &a);
    printf("a: %d\n", a);
    dshow(&d);
    free(d.values);

    */

    //DQueue q;
    struct dinQueue q;
    DinitQueue(&q);

    int k;
    int l;
    int h;
    
    Denqueue(&q, 6);
    Denqueue(&q, 8);
    Denqueue(&q, 10);
    Denqueue(&q, 12);
    qshow(&q);
    Ddequeue(&q, &k);
    Ddequeue(&q, &h);
    Dfront(&q, &l);
    
    free(q.values);
    return 0;
}