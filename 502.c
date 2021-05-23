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

//5
void insertOrd (LInt *l, int x){

    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;

    LInt *cur = l;
    while (*cur && (*cur)->valor < x) {
        cur = &((*cur)->prox);
    }
    new->prox = *cur;
    *cur = new;
}

//6
int removeOneOrd (LInt *l, int x){
    
    int r = 1;
    LInt *cur = l;

    while (*cur && (*cur)->valor != x) {
        cur = &((*cur)->prox);
    }
    if (*cur) {
        r = 0;
        LInt del = *cur;
        *cur = (*cur)->prox;
        free(del);
    }
    return r;
}

//9
LInt parteAmeio (LInt *l){
    int n = 0;
    int i = 0;
    LInt *c = l;
    LInt new_head = NULL;
    LInt curr = NULL;

    while (*c){
        n++;
        c = &((*c)->prox);
    }

    while (*l && i < n/2) {
        if(!new_head) new_head = curr = *l;
        else curr = *l;
        *l = (*l)->prox;
        i++;
    }
    curr->prox = NULL;

    return new_head;
}

//10
int removeAll (LInt *l, int x){
    int c = 0;
    while (*l) {
        if ((*l)->valor == x) {
            *l = (*l)->prox;
            c++;
        }
        else l = &((*l)->prox);
    }
    
    return c;
}

//12
int removeMaiorL (LInt *l){
    
    LInt *cur = l;
    LInt *ptr = l;
    int max = (*cur)->valor;

    while (*cur) {
        if ((*cur)->valor > max) max = (*cur)->valor;
        cur = &((*cur)->prox);
    }

    while (*l && (*l)->valor != max) {
        l  = &((*l)->prox);
    }
    
    LInt tmp = *l; 
    *l = (*l)->prox;
    free(tmp);


    return max;
}

//13
void init (LInt *l){
    LInt prev = NULL;

    while ((*l)->prox) {
        prev = *l;
        l = &((*l)->prox);
    }
    free(*l);
    if(prev) prev->prox = NULL;
    else *l = NULL;
}

//14
void appendL (LInt *l, int x){

    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;

    if(!(*l)) *l = new; 
    
    else {
        while (*l && (*l)->prox) {
            l = &((*l)->prox);
        }
        (*l)->prox = new;
    }
}

//15
void concatL (LInt *a, LInt b){

    if(!(*a)) *a = b; 
    else{
        while ((*a)) {
            a = &((*a)->prox);
        }
        
        *a = b;
    }
}

//16
LInt cloneL (LInt l) {
    LInt new_head = NULL;
    LInt curr = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = NULL;

        if(new_head == NULL) new_head = curr = new;
        else {
            curr->prox = new;
            curr = new; 
        }
        l = l->prox;
    }
    return new_head;
}

//17
LInt cloneRev (LInt l) {
    LInt new_head = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = new_head;
        new_head = new;
        l = l->prox;
    }
    return new_head;
}

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

//19
int take (int n, LInt *l){
    int i = 0;
    for (i = 0; *l && n > 0 ; i++, n--, l = &((*l)->prox));
    free(*l);
    *l = NULL;
    return i;
}

//20
int drop (int n, LInt *l){
    int c = 0;
    while (*l && n > 0) {
        LInt tmp = *l;
        n--;
        c++;
        *l = (*l)->prox;
        free(tmp);
    }
   
    return c;
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

//25
void remreps (LInt l){
    if (l != NULL) {
        while (l->prox != NULL) {
            if (l->prox->valor == l->valor) {
                LInt tmp = l->prox;
                l->prox = tmp->prox;
                free(tmp);
            }else l = l->prox;
        }
    }
}

//26
LInt rotateL (LInt l){
    
    if (l == NULL || l->prox == NULL) return l;
    
    LInt fst = l;
    LInt snd = l->prox;

    while (l->prox != NULL) l = l->prox;
    
    fst->prox = NULL;
    l->prox = fst;

    return snd;
}

//27
LInt parte (LInt l){
    
    LInt new_head, tmp;
    new_head = temp = l->prox;

    while(l && l->prox) {

        tmp->prox = l->prox;
        tmp = l->prox;

        l->prox = l->prox->prox;
        l = l->prox;

        temp->prox = NULL;
    }
    return new_head;
}
typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} *ABin;

//28
int altura (ABin a){

    if (a == NULL) return 0;

	return 1 + (altura(a->esq) > altura(a->dir) ? altura(a->esq) : altura(a->dir));
}

//29
ABin cloneAB (ABin a) {
    if (!a) return NULL;
    
    ABin res = malloc(sizeof(struct nodo));
    res->valor = a->valor;
    res->esq = cloneAB(a->esq);
    res->dir = cloneAB(a->dir);

    return res;
}

//30
void mirror (ABin *a) {
    if (*a) {
        ABin tmp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = tmp;
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
    }
}

ABin a = newABin(2, newABin(4, newABin(6, NULL, newABin(8, NULL, NULL)), NULL), newABin(10, NULL, newABin(22, newABin(25, NULL, NULL), NULL)));
