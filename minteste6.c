#include <stdlib.h>


typedef struct nodo {
    int valor;
    struct nodo * prox;
} *LInt;


int calcula(LInt l) {

    int s = 0;
    int c = 0;

    while (c < 12) {

        if (c % 2 != 0) {
            s += l->valor;
        }
        
        l = l->prox;
        c++;
    }
    
    return s;
}

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

int glob = 0;

ABin procura(ABin a) {

    ABin b = a;
    int changed = 1;

    int i;
    for (i = 0; i < 12; i++) {
        if (i == 11) {
            return a;
        }
        else if (a->esq != NULL && changed) {
            a = a->esq;
        }
        else if(a->esq == NULL) {
            a = b->dir
            changed = 0;
        }
    }
}



int main {

}