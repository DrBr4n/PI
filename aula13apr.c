#include <stdio.h>
/*
--- Exemplo: stack de inteiros ---
push   acrescentar um elemento
pop    retirar um elemento
top    qual o proximo elemento a ser retirado
empty  saber se a stack esta vazia
*/

int A;         //A é uma variavel do tipo int
typedef int B; //B é um tipo equivalente a int
B x;           //x é uma variavel do tipo B, i.e., int

typedef struct stack {
    int valores[100];
    int quantos;
} STACK; //STACK é um tipo do tipo stack

STACK push (int x, STACK s) {
    s.valores[s.quantos++] = x;
    return s;
}

void pop (STACK* s) {
    s->quantos--;
    //return s;
}

int top (STACK s) {
    return s.valores[s.quantos - 1];
}

int empty(STACK s) {
    return (s.quantos == 0);
}

int main(int argc, char * argv[]) {

    STACK s1;
    s1.quantos = 0;

    s1 = push(2, s1);
    printf("stack: %d\n", top(s1));
    s1 = push(4, s1);
    printf("stack: %d\n", top(s1));
    s1 = push(6, s1);
    printf("stack: %d\n", top(s1));

    pop(&s1);
    printf("stack: %d\n", top(s1));

}