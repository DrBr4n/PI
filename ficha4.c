#include <stdio.h>
#include <string.h>

//1.1
int contaVogais(char *s) {

    char vogais[10] = {'a','e','i','o','u','A','E','I','O','U'};

    int r = 0;

    for (int j = 0; s[j] != '\0'; j++) {
        for (int i = 0; i < 10; i++) {
            if (s[j] == vogais[i]) {
                r++;
                break;
            }
        }
    }
    
    return r;
}

//1.2
int retiraVogaisRep (char *s) {

    char vogais[5] = {'a','e','i','o','u'};
    int r = 0;

    for (int j = 0; s[j] != '\0'; j++) {
        for (int i = 0; i < 5; i++) {
            if (s[j] == vogais[i]) {
                if (s[j] == s[j+1]) {
                    for (int k = j+1; s[k] != '\0'; k++){
                        s[k] = s[k+1];
                    }
                    r++;
                    j--;
                }
            }
        }
    }
    return r;
}

//1.3
int duplicaVogaisv01 (char *s) {
    printf("Input: %s\n", s);

    //array com as vogais
    char vogais[10] = {'a','e','i','o','u','A','E','I','O','U'};

    //descobrir length do s 
    int lenS = 0;
    for(int i = 0; s[i] != '\0'; i++)
        lenS++;

    //quantas vogais vamos duplicar
    int toAdd = contaVogais(s);

    //array auxiliar com o tamanho de s + as vogais que vamos adicionar
    int auxN = lenS + toAdd;
    char aux[auxN];

    //percorrer s e preencher aux
    int r;
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        aux[c] = s[i]; //adicionar os chars de s
        for (int j = 0; j < 10; j++) {
            if (s[i] == vogais[j]) { //se for vogal duplica
                r++;
                c++;
                aux[c] = s[i];
                break;
            }
        }
       c++; 
    }

    for (int i = 0; i < auxN; i++) {
        printf("%c", aux[i]);
    }
    printf("\nr: %d\n", r);
    return r;
}

int duplicaVogaisv02 (char *s) {
    printf("Input: %s\n", s);

    //get length of s
    int lenS = 0;

    for (int i = 0; s[i] != '\0'; i++)
        lenS++;

    //meter espaço na string para poder duplicar
    strcat(s, "          ");

    //passa pelo s e duplica as vogais
    int r = 0;
    for (int i = 0; i < lenS; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                r++;
                lenS++;
                for (int k = lenS-1; k > i; k--) s[k] = s[k-1];
                i++;
            }
    }
    printf("Output: %s\n", s);
    return r;
}

//2.1
int ordenado(int v[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (v[i] > v[j]) {
                return 0;
            }
        }
    }
    return 1;
}

//2.2
void merge(int a[], int na, int b[], int nb, int r[]) {

    int ca = 0;
    int cb = 0;

    for (int m = 0; m < na + nb; m++) {
        if (a[ca] <= b[cb]) {
            r[m] = a[ca];
            ca++;
        }
        else if (a[ca > b[cb]]){
            r[m] = b[cb];
            cb++;
        }  
    }
}

//2.3
int partitionv01(int v[], int N, int x) {

    int aux[N];
    int low = 0;
    int top = N - 1;
    int result = 1;

    for (int i = 0; i < N; i++) {
        if (v[i] < x) {
            aux[low] = v[i];
            low++;
            result++;
        }
        else if (v[i] < x) {
            aux[top] = v[i];
            top--;
        }
    }

    return result;
}

void sort(int * v, int N) {

    for (int i = 0; i < N; i++) {

        int min = i;

        for (int j = i+1; j < N; j++) {
            if (v[j]< v[min]) {
                min = j;
            }
        }
        
        if(min != i) {
            int tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
        }
    }
}

int partitionv02(int v[], int N, int x) {

    int r = 0;

    sort(v, N);

    for (int i = 0; v[i] <= x; i++) r++;

    return r;
}

int main(int argc, char *argv[]) {
    //char *argv[] == char **argv

    //printf("Vogais em \"%s\": %d\n", argv[1], contaVogais(argv[1]));

    //printf("Vogais retiradas em \"%s\": %d\n", argv[1], retiraVogaisRep(argv[1]));

    //duplicaVogaisv01(argv[1]);

    //char * str = strdup(argv[1]);
    //duplicaVogaisv02(str);

    //int na = 5;
    //int nb = 5;
    //int r[10];
    //int a[5] = {1,3,5,7,9};
    //int b[5] = {2,4,8,10,12};
    //merge(a, na, b, nb, r);

    int b[8] = {2,4,8,10,12,5,6,7};
    
    int n = 8;
    printf("%d\n", partitionv02(b, n, 4));

}

//falta o 2.3