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

//1
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

//2
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

//3
typedef LInt QueueC;

void initQueueC (QueueC *qc) {
    *qc = malloc(sizeof(struct slist));
    (*qc)->valor = NULL;
    (*qc)->prox = NULL;
}

int QisEmptyC (QueueC qc) {
    return (qc->prox == NULL);    
}

void enqueueC (QueueC *qc, int x) {

    LInt new = malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;

    if (QisEmptyC(*qc)) {
        *qc = new;
        new->prox = new; //apontar para a propria celula visto que é circular
    } else {
        new->prox = (*qc)->prox; //apontar para o primeiro elemento
        (*qc)->prox = new; //fazer com que o penultimo elemento aponte para o ultimo
        *qc = new; //apontar para o ultimo elemento
    }
}

int dequeueC (QueueC qc, int *x) {
    if (QisEmptyC(qc)) {
        return 1;
    } else {
        if (qc == qc->prox) { //se forem iguais é o unico elemento da lista
            *x = qc->valor;
            qc->prox = NULL; //tornar a lista vazia
        } else {
            *x = qc->prox->valor;
            qc->prox = qc->prox->prox; //deixar de apontar para o primeiro elemento e apontar para o segundo
        }
    }
}

int frontC (QueueC qc, int *x) {
    if (QisEmptyC(qc)) 
        return 1;
    else 
        *x = qc->prox->valor;
    return 0;
}

int dequeueCC (QueueC *qc, int *x) {
    if (QisEmptyC(*qc)) {
        return 1;
    } else {
        if (*qc == (*qc)->prox) {
            *x = (*qc)->valor;
            (*qc)->prox = NULL;
        } else {
            *x = (*qc)->prox->valor;
            (*qc)->prox = (*qc)->prox->prox;
        }
    }
}

int frontCC (QueueC *qc, int *x) {
    if (QisEmptyC(*qc)) 
        return 1;
    else 
        *x = (*qc)->prox->valor;
    return 0;
}

//4
typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;

void initDeque (Deque *q) {
    q->back = NULL;
    q->front = NULL;
}

int DisEmpty (Deque q) {
    return (q.back == NULL && q.front == NULL);
}

int pushBack (Deque *q, int x) {
    DList new = malloc(sizeof(struct dlist));
    new->valor = x;
    new->ant = new->prox = NULL;

    if (DisEmpty(*q)) {
        (*q).back = new;
        (*q).front = new;
    }
    else {
        new->prox = (*q).back;
        (*q).back->ant = new;
        (*q).back = new;
    }
}

int pushFront (Deque *q, int x) {
    DList new = malloc(sizeof(struct dlist));
    new->valor = x;
    new->ant = new->prox = NULL;
    
    if (DisEmpty(*q)) {
        (*q).back = new;
        (*q).front = new;
    }
    else {
        new->ant = (*q).front;
        (*q).front->prox = new;
        (*q).front = new;
    }
}

int popBack (Deque *q, int *x) {
    if (DisEmpty(*q)) 
        return 1;
    else if ((*q).back == (*q).front) {//se for o ultimo elemento zerar a queue 
        *x = (*q).front->valor;
        free((*q).back);
        initDeque(q);
    }
    else {
        *x = (*q).back->valor;
        DList tmp = (*q).back->prox;
        free((*q).back);
        (*q).back = tmp;
        (*q).back->ant = NULL;
    }
    return 0;
}

int popFront (Deque *q, int *x) {
    if (DisEmpty(*q)) 
        return 1;
    else if ((*q).back == (*q).front) {//se for o ultimo elemento zerar a queue 
        *x = (*q).front->valor;
        free((*q).front);
        initDeque(q);
    }
    else{
        *x = (*q).front->valor;
        DList tmp = (*q).front->ant;
        free((*q).front);
        (*q).front = tmp;
        (*q).front->prox = NULL;
    }
    return 0;
}

int popMax (Deque *q, int *x) {
    if (DisEmpty(*q)) 
        return 1;
    else {
        DList ptr = q->back;
        int max = 0;
        while (ptr != NULL) {
            if (ptr->valor > max) {
                max = ptr->valor;
            }
            ptr = ptr->prox;
        }

        ptr = q->back;
        while (ptr->valor != max) ptr = ptr->prox;

        *x = ptr->valor;
        ptr->ant->prox = ptr->prox; //anterior fica a apontar para a proxima
        ptr->prox->ant = ptr->ant; //proxima fica a apontar para a anterior
        free(ptr);
    }
    return 0;
}

int backD (Deque q, int *x) {
    if (DisEmpty(q)) 
        return 1;
    else
        *x = q.back->valor;
    return 0;
}

int frontD (Deque q, int *x) {
    if (DisEmpty(q)) 
        return 1;
    else
        *x = q.front->valor;
    return 0;
}


int main() {

    Deque d;
    initDeque(&d);
    printf("DisEmpty: %d\n", DisEmpty(d));
    pushBack(&d, 2);
    pushBack(&d, 4);
    pushFront(&d, 10);
    pushFront(&d, 20);
    pushFront(&d, 8);
    int a;
    popMax(&d, &a);
    printf("max: %d", a);

    return 0;
}