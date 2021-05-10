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
        *q = NULL;
    }

    int QisEmpty (Queue q) {
        return (q == NULL);    
    }

    void enqueue (Queue *q, int x) {
        if (!QisEmpty(*q)) {
            q->inicio->valor = x;
            q->inicio->prox = NULL;
        }
        
        Queue t = *q;
        q = malloc(sizeof(Queue));
        q->fim->valor = x;
        q->fim->prox = t; 
    }

    int dequeue (Queue *q, int *x) {}
    int front (Queue q, int *x) {}


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
        //fse
        Queue q;

        return 0;
    }