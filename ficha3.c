#include <stdio.h>

void swapM(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap(int v[], int i, int j) {

  int c = 2;

    for(int idx = 0;c > 0;idx++) {
        if (v[idx] == i) {
            v[idx] = j;
            c--;
          }
        else if (v[idx] == j) {
                 v[idx] = i;
                 c--;
          }
    }
}

int soma(int v[], int N) {

    int s = 0;

    for (int i = 0; i < N; i++)
        s += v[i];

    return s;
}

void inverteArray (int v[], int N) {

    int middle = N/2;
    N--;

    for (int i = 0; i < middle; i++) {
        swap(v, v[i], v[N]);
        N--;
    }
}

void inverteArrayy (int v[], int N) {

    int middle = N/2;
    N--;

    for (int i = 0; i < middle; i++) {
        swapM(&v[i], &v[N]);
        N--;
    }
}

int maximum(int v[], int N, int *m) {

    if (N > 0) {
        *m = v[0];

        for (int i = 1; i < N; i++)
            if (v[i] > *m)
                *m = v[i];

        return 0;
    }
    else return 1;
}

void quadrados(int q[], int N) {

    q[0] = 0;

    for (int i = 0; i < (N-1); i++) {
        q[i+1] = q[i] + (2 * i + 1);
    }
}

void pascal(int v[][21], int N){

    for (int l = 0; l <= N; l++) {
        for (int c = 0; c <= l; c++) {
            if (c == 0 || c == l) v[l][c] = 1;
            else v[l][c] = v[l-1][c-1] + v[l-1][c];
        }
    }
}

int main() {
    int N = 20;
    int v[N+1][N+1];
    pascal(v, N);

    for (int i = 0; i <= N; i++){
        for (int c = 0; c <= i; c++)
            printf("%d ", v[i][c]);

        putchar('\n');
    }

    return 0;
}