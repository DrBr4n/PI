int procura(int x, int v[], int N) {
    int i = 0;

    while (i < N && v[i] != x)
        i++;
    
    if (i!=N) return (i);
    else return(-1);     
}

int procuraOrdenada (int x, int v[], int N) {
    //v está ordenado
    int i = 0;

    while (i<N && v[i] < x)
        i++;

    if (i < N && v[i] == x) return i;
    else return -1;
}

int procuraB(int x, int v[], int N) {
    return (procuraEntre(x, v, N, 0, N-1));
}


int procuraEntre(int x, int v[], int N, int inf, int sup) {
    //procura x em v entre a e b
    int meio;
    int r;

    if(inf > sup) r = (-1);
    else {
        meio = (inf+sup)/2;

        if(v[meio] == x) r = meio;

        else if(v[meio] > x) r = (procuraBinaria (x, v, B, inf, meio-1));

        else r = (procuraBinaria(x, v, n, meio + 1, sup));
    }
    return r;
}

int procuraBinaria(int x, int v[], int N) {
    int r, meio;

    if(N == 0) r = -1;
    else {
        meio = N/2;
        if(v[meio] == x) r = meio;
        else if(v[meio] > x) r = procuraBinaria(x, v, meio);
        else r = meio + 1 + procuraBinaria(x, v + meio + 1, N-meio-1); 
    }
    return r;
}