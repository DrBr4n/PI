#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin(int r, ABin e, ABin d) {
    ABin a = malloc(sizeof(struct nodo));
    if (a != NULL) {
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }
    return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

int nNodos(ABin a) {
    int r = 0;

    if (a) {
        r++;
        r += nNodos(a->dir);
        r += nNodos(a->esq);
    }
    return r;
}

int altura(ABin a) {
    int r = 0;
    
    while (a != NULL) {
        r++;
        if (nNodos(a->esq) > nNodos(a->dir)) a = a->esq;
        else a = a->dir;
    }

    return r;
}

int nFolhas (ABin a) {
    int r = 0;

    if (a) {
        if(a->dir == NULL && a->esq == NULL) r++;
        r += nFolhas(a->dir);
        r += nFolhas(a->esq);
    }
    return r;
}


ABin maisEsquerda (ABin a) {
    while (a->esq != NULL) a = a->esq;
    return a;
} 

void imprimeNivel(ABin a, int l) {
    if(a) {
        if (l == 0) printf("%d ", a->valor);
        else{
            imprimeNivel(a->esq, l-1);
            imprimeNivel(a->dir, l-1);
        }
    }
}

//testa se x ocorre em a
int procuraE (ABin a, int x) {
    int r = 0;
    if(a) {
        if (a->valor == x) r = 1;
        else r = procuraE(a->esq, x) || procuraE(a->dir, x);
    }
    return r;
}

struct nodo *procura (ABin a, int x) {
    struct nodo *r = NULL;
    if (a) {
        if(a->valor == x) r = a;
        else if (a->valor > x) r = procura(a->esq, x);
        else r = procura(a->dir, x);        
    }
    return r;
}
//fazer de forma iterativa?

int nivel (ABin a, int x) {
    int r = -1;
    if(a) {
        if (a->valor == x) r = 0;
        else if (x < a->valor) r = nivel(a->esq, x);
        else r = nivel(a->dir, x);

        if (r != -1) r++;  
    }
    return r;
}

void imprimeAte (ABin a, int x) {
    if (a) {
        imprimeAte(a->esq, x);
        printf("%d ", a->valor);
        imprimeAte(a->dir, x);
    }
}

int main(int argc, char * argv[]) {

    ABin left = newABin(50, newABin(200, NULL, NULL), NULL);
    ABin right = newABin(70, newABin(300, newABin(1, NULL, NULL), NULL), newABin(400, NULL, NULL));
    ABin raiz = newABin(101, left, right);

    printf("nNodos: %d\n", nNodos(raiz));
    printf("altura: %d\n", altura(raiz));
    printf("nFolhas: %d\n", nFolhas(raiz));
    ABin es = maisEsquerda(raiz);
    printf("maisEsquerda: %d\n", es->valor);
    imprimeNivel(raiz, 3);
    putchar('\n');
    printf("procuraE: %d\n", procuraE(raiz, 0));
    ABin c = procura(raiz, 1);
    printf("%d\n", c->valor);

    return 0;
}