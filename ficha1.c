#include <stdio.h>
/*
*1
1)
    int x, y;
    x = 3; y = x+1;
    x = x*y; y = x + y;
    printf("%d %d\n", x, y);

    output: 12 16

2)
    int x, y;
    x = 0;
    printf ("%d %d\n", x, y);

    output: 0 0

3)
    (assuma que os códigos ASCII dos caracteres ’A’, ’0’, ’ ’ e ’a’ são respectivamente 65, 48, 32 e 97)

    char a, b, c;
    a = ’A’; b = ’ ’; c = ’0’;
    printf ("%c %d\n", a, a);
    a = a+1; c = c+2;
    printf ("%c %d %c %d\n", a, a, c, c);
    c = a + b;
    printf ("%c %d\n", c, c);

    output: A 65
            B 66 2 50
            b 98

4)
    int x, y;
    x = 200; y = 100;
    x = x+y; y = x-y; x = x-y;
    printf ("%d %d\n", x, y);

    output: 100 200

*2
a)
    int x, y;
    x = 3; y = 5;
    if (x > y)
        y = 6;
    printf ("%d %d\n", x, y);

    output: 3 5

b)
    int x, y;
    x = y = 0;
    while (x != 11) {
        x = x+1; y += x;
    }
    printf ("%d %d\n", x, y);

    output: 11 66

c)
    int i;
    for (i=0; (i<20) ; i++)
        if (i%2 == 0) putchar (’_’);
        else putchar (’#’);

    output: _#_#_#_#_#_#_#_#_#_# 

d)
    void f (int n) {
        while (n>0) {
            if (n%2 == 0) putchar (’0’);
            else putchar (’1’);
            n = n/2;
        }
        putchar (’\n’);
    }
    int main () {
        int i;
        for (i=0;(i<16);i++)
            f (i);
    return 0;

    output: 1
            01
            11
            001
            101
            011
            111
            0001
            1001
            0101
            1101
            0011
            1011
            0111
            1111
*/

void fst (int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            putchar('#');
        putchar('\n');
    }
}

void snd (int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ( (i+j) % 2 == 0) putchar('#');
            else putchar('_');
        }
        putchar('\n');
    }
}

void trdh (int n) {

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            putchar('#');
        }
        putchar('\n');
    }

    for (int i = n-1; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            putchar('#');
        }
        putchar('\n');
    }
}

void trdv (int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n*2 ; j++) {
            if (j >= n-i && j <= n+i) putchar('#');
            else putchar(' ');
        }
        putchar('\n');
    }
}

void circ (int raio){

    for(int i=0; i<=2*raio; i++) {
        for(int j=0; j<= 2*raio; j++) {

            if(((i-raio)*(i-raio) + (j-raio)*(j-raio)) <= raio*raio) {
                putchar('#');
            }
            else putchar (' ');
        }
        putchar('\n');
    }
}

void window(int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == n-1) putchar('#');
            else putchar(' ');
        }
        putchar('\n');
    }
}

int main () {

    //fst(10);
    //snd(11);
    //trdh(7);
    //trdv(7);
    //circ(4);
    window(6);

}