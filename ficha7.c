#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista(Palavras l) {
    l->palavra = NULL;
    l->prox = NULL;
    l->ocorr = 0;
}

int quantasP (Palavras l) {

    int r = 0;

    while (l != NULL) {
        r++;
        l = l->prox;
    }

    return r;
}

void listaPal (Palavras l) {

    while (l != NULL) {
        printf("Ocorr: %d, Palavra: %s\n", l->ocorr, l->palavra);
        l = l->prox;
    }
}

char * ultima (Palavras l) {
    while (l->prox != NULL) l = l->prox;

    return l->palavra;
}

Palavras acrescentaInicio (Palavras l, char *p) {

    Palavras k = NULL;

    k = (Palavras) malloc(sizeof(struct celula));

    k->palavra = p;
    k->ocorr = 1;
    k->prox = l;

    return k;
}

Palavras acrescentaFim (Palavras l, char *p) {

    Palavras head = l;

    Palavras k = NULL;

    k = (Palavras) malloc(sizeof(struct celula));

    k->palavra = p;
    k->ocorr = 1;
    k->prox = NULL;

    while (l->prox!= NULL) l = l->prox;

    l->prox = k;

    return head;
}

Palavras acrescenta (Palavras l, char *p) {

    Palavras head = l;

    while (l != NULL) {
        if (l->palavra == p) {
            l->ocorr++;
            return head;
        }
        l = l->prox;
    }

    return acrescentaInicio(head, p);
}

struct celula * maisFreq (Palavras l) {

    Palavras ptr = l;

    int max = 0;
    int idx = 0;

    for (int i = 0; l != NULL; i++) {
        if (l->ocorr > max) {
            max = l->ocorr;
            idx = i;
        }
        l = l->prox;
    }

    for (int i = 0; i < idx; i++) ptr = ptr->prox;

    
    return ptr;
}

int main() {
/*
    //struct celula p;
    Palavras p = NULL;
    //libertaLista(p);

    char * o = "Sopa";
    char * e = "Massa";
    char * i = "Atum";
    char * u = "Bate";
    char * x = "Batata";

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};


    p = acrescentaInicio(p, e);
    p = acrescentaFim(p, i);
    p = acrescentaInicio(p, o);
    p = acrescentaFim(p, u);
    p = acrescenta(p, x);
    p = acrescenta(p, o);
    p = acrescenta(p, i);
    p = acrescenta(p, i);
    listaPal(p);
    printf("Quantas: %d\n", quantasP(p));
    printf("Ultima: %s\n", ultima(p));

    struct celula * m = maisFreq(p);

    printf("Mais freq: %s\n", m->palavra);
*/
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    libertaLista (dic);

    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));
    
    p = maisFreq (dic);
    printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    
    printf ("\n_________ Fim dos testes _________\n\n");
    
    return 0;
}