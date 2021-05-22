#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//1
int length (LInt l){

    int r = 0;

    while (l != NULL) {
        l = l->prox;
        r++;
    }

    return r;
}

//2
void freeL(LInt l) {
    while(l) {
        LInt temp = l;
        l = l->prox;
        free(temp);
    }
}

//3
void imprimeL(LInt l) {
    while (l != NULL) {
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

//4
LInt reverseL (LInt l){

    LInt prev = NULL;
    LInt cur = l;
    
    while (l != NULL) {
        cur = l;
        //salta com o l para a frente para nao perder o resto da lista
        l = l->prox;
        //liga a celula atual a ultima que passou
        cur->prox = prev;
        //atualiza a ultima celula que passou
        prev = cur;
    }

    return cur;
}

//5
//void insertOrd (LInt *l, int x) {
//
//    LInt head = *l;
//    LInt prev = NULL;
//
//    LInt new = malloc(sizeof(struct lligada));
//    new->valor = x;
//    new->prox = NULL;
//
//    if ((*l)->valor > x) {
//        new->prox = (*l);
//        *l = new;
//    }
//    else{
//        while (*l != NULL) {
//            if ((*l)->prox->valor > x) {
//                new->prox = (*l)->prox;
//                (*l)->prox = new;
//                break;
//            }
//            *l = (*l)->prox; 
//        }
//    }
//    *l = head;
//}

//18
int maximo (LInt l){
    
    int max = l->valor;

    while (l != NULL) {
        if (l->valor > max)
            max = l->valor;
        l = l->prox;
    }

    return max;
}

//21
LInt NForward (LInt l, int N){
    
    while (l != NULL && N > 0) {
        l = l->prox;
        N--;
    }
    return l;
}

//22
int listToArray (LInt l, int v[], int N){
    
    int i = 0;
    for ( ; l != NULL && i < N; i++, l = l->prox) {
        v[i] = l->valor;
    }

    return i;
}

//23
LInt arrayToList (int v[], int N){
    
    LInt head = NULL;

    if (N > 0) {
        LInt prev = malloc(sizeof(struct lligada));
        prev->valor = v[0];

        head = prev;

        int i;
        for (i = 1; i < N; i++) {
            LInt new = malloc(sizeof(struct lligada));
            new->valor = v[i];
            new->prox = NULL;
            prev->prox = new;
            prev = new;
        }
    }

    return head;
}

//24
LInt somasAcL (LInt l) {
    
    LInt head = NULL;
    LInt prev = NULL;

    int ac = 0;

    while (l != NULL) {
        ac += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = ac;
        new->prox = NULL;

        if (head == NULL) head = new; 
        else prev->prox = new;
        
        prev = new;
    
        l = l->prox;
    }

    return head;
}

