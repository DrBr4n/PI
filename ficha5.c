#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a){
    int i,notaF;

    float somaMiniT = 0;

    for (i = 0; i < 6; i++){
        somaMiniT += a.miniT[i];
    
        somaMiniT = (somaMiniT * 20) / 12;

        if(somaMiniT >= 8 && a.teste >= 8)
            notaF = somaMiniT*0.3 + a.teste*0.7;
    
    }
}

int procuraNum(int num, Aluno t[], int N) {

    for (int i = 0; i < N; i++) {
        if (num == t[i].numero)
            return i;

        else if (num == t->numero)
            return (-1);
    }

    return (-1);
}

void ordenaPorNum(Aluno t[], int N) {

    for (int i = 0; i < N; i++) {

        int min = i;

        for (int j = i+1; j < N; j++) {
            if (t[j].numero < t[min].numero) {
                min = j;
            }
        }
        
        if(min != i) {
            Aluno tmp = t[i];
            t[i] = t[min];
            t[min] = tmp;
        }
    }
}

void criaIndPorNum (Aluno t[], int N, int ind[]) {

    for (int i = 0; i < N; i++) {
        ind[i] = i;
    }
    
    for (int i = 0; i < N; i++) {

        int min = i;

        for (int j = i+1; j < N; j++) {
            if (t[ind[j]].numero < t[ind[min]].numero) {
                min = j;
            }
        }

        if(min != i) {
            int tmp = ind[i];
            ind[i] = ind[min];
            ind[min] = tmp;
        }
    }

    for (int i = 0; i < 7; i++)
    {
        printf("->%d\n", ind[i]);
    }
}

void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

void imprimeTurma(int ind[], Aluno t[], int N) {

    for (int i = 0; i < N; i++) {
        imprimeAluno(&t[ind[i]]);
    }
}


int main(int argc, char * argv[]) {

    Aluno Turma1 [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
                       };

    printf("idx: %d\n", procuraNum(atoi(argv[1]), Turma1, 7));

    //ordenaPorNum(Turma1, 7);

    //int ind[7];
    //criaIndPorNum(Turma1, 7, ind);

    int ind[7] = {3,1,0,6,5,4,2};

    //imprimeTurma(ind,Turma1, 7);

    return 0;
}