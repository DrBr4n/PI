#include <stdio.h>
#include <stdlib.h>

//1
void one() {

    int max = -1;
    int c = -1;
    while (c != 0) {
        scanf("%d", &c);
        if (c > max) max = c;
    }

    printf("Max: %d\n", max);
}

//2
void two() {
    int sum = 0;
    int len = 0;
    int c = -1;

    while(c != 0) {
        scanf("%d", &c);
        sum += c;
        len++;
    }
    printf("Média: %d\n", sum / (len - 1));
}

//3
void three() {

    int max = -1;
    int sndMax = -1;
    int c = -1;
    while (c != 0) {
        scanf("%d", &c);
        if (c > max) {
            sndMax = max;
            max = c;
        }    
    }

    printf("Segundo max: %d\n", sndMax);
}

//4
int bitsUm(unsigned int n) {
    int r = 0;
    while (n) {
        r+= (n % 2);
        n = n / 2;
    }
    return r;
}

//5
//int trailingZ (unsigned int n) {
//    if(n % 2) return 0;
//    else return 1 + trailingZ(n >> 1);
//}

//6
int qDig(unsigned int n) {
    int r = 1;
    while (n > 9) {
        n = n / 10;
        r++;
    }
    return r;
}

//7
char * strcats(char s1[], char s2[]) {

    char * res = s1;
    int i,j;
    for (i = 0; s1[i] != '\0'; i++) res++;

    for (j = 0; s2[j] != '\0'; j++) {
        *res = s2[j];
        res++;
    }
    
    
    *res = '\0';
    
    return res;
}

//8
//char * strcpys(char * dest, char source[]) {
//
//    char * result = source;
//
//    for (int i = 0; source[i] != '\0'; i++)
//    {
//        printf("%c", source[i]);
//        //*dest = source[i];
//        //dest++;
//    }
//    
//    return result;
//}


//14
char charMaisfreq (char s[]) {

    if (s == "") return 0;

    char r = '?';
    int max = 0;
    int c = 0;

    int i, j;
    for (i = 0; s[i]; i++) {
        for (j = 0; s[j]; j++) {
            if (s[j] == s[i])
              c++;
        }
        if (c > max) {
            max = c;
            r = s[i];
        }
        c = 0;
    }
    return r;
}

//15
int iguaisConsecutivos (char s[]) {
    
    int max = 0;
    int counter = 1;
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i+1]) counter++;
        else counter = 1;
        if (counter > max) max = counter;
    }
    return max;
}

//16
int elemStr(char * s, int i, int n) {
    int r = 0;
    for(; i < n; i++) {
        if (s[i] == s[n]) return 1;
    }
    return r;
}

int difConsecutivos(char s[]) {
    int max = 0;
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
        int counter = 0;
        for (j = i; s[j] != '\0'; j++) {
            if (!elemStr(s, i, j)) counter++;
            else break;
        }
        if (counter > max) max = counter;
    }
    return max;  
}

//20
int contaPal (char s[]) {
    int r = 0;
    int inword = 0;
    int i;
    for (i = 0; s[i]; i++) {
        if(s[i] == ' ' || s[i] == '\n') {
            if (inword) r++;
            inword = 0;
        }
        else
            inword = 1;
    }
    if (inword) r++;

    return r;
}

//21
int contaVogais (char s[]) {
    int r = 0;
    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            r++;
    }
    
    return r;
}

//22
int contida (char a[], char b[]) {
    
    int i, j, k;
    for (i = 0; a[i]; i++) {
        k = 0;
        for (j = 0; b[j]; j++) {
            if (a[i] == b[j]) k = 1; 
        }
        if (k == 0) {
            return 0;
        }
    }
    return 1;
}

//23
int palindroma (char s[]) {
    
    int r = 1;
    int len = 0;
    int i = 0;

    for (; s[i]; i++) len++;

    int m = len/2;
    for (i = 0; i < m; i++) {
        if (s[i] != s[len-1]) {
            r = 0;
            break;
        }
        len--;
    }
    return r;
}

//24     
int remRep (char texto []) {
    int i, r = 0;
    for (i = 0; texto[i]; i++) {
        r++;
        if (texto[i] == texto[i + 1]) {
            int k;
            for (k = i; texto[k]; k++) {
                texto[k] = texto[k + 1];
            }
            i--;
            r--;
        }
    }
    return r;
}

//25
int limpaEspacos (char texto[]) {
    int i, r = 0;
    for (i = 0; texto[i]; i++) {
        r++;
        if (texto[i] == ' ' && texto[i + 1] == ' ') {
            int k;
            for (k = i; texto[k]; k++) {
                texto[k] = texto[k + 1];
            }
            i--;
            r--;
        }
    }
    return r;
}

//26
void insere (int s[], int N, int x){
    int i;
    for (i = 0; i < N; i++) {
        if (s[0] > x) {
            int k;
            for (k = N; k >= i; k--) {
                s[k]= s[k - 1];
            }
            s[i] = x;
            break;
        }
        else if (s[N-1] < x) {
            s[N] = x;
        }
        else if (s[i] <= x && s[i + 1] > x) {
            int k;
            for (k = N; k > i; k--) {
                s[k]= s[k - 1];
            }
            s[i + 1] = x;
            break;
        } 
    }
}

//27
void merge (int r [], int a[], int b[], int na, int nb){

    int i;
    int ca = 0;
    int cb = 0;
    for (i = 0; i < na+nb; i++) {
        if (a[ca] <= b[cb] && ca < na || cb >= nb) r[i] = a[ca++];
        else r[i] = b[cb++];
    }
}

//28
int crescente (int a[], int i, int j){
    int r = 1;
    
    for (; i < j; i++) if (a[i] > a[i + 1]) r = 0;

    return r;
}

//29
int retiraNeg (int v[], int N){

    int i;
    for (i = 0; i < N; i++) {
        if (v[i] < 0) {
            int k;
            for (k = i--; k < N; k++) v[k] = v[k + 1];
            N--;
        }
    }

    return r;
}

//30
int menosFreq (int v[], int N){
    int r = v[0];
    int i = 0;
    int counter = 1;
    int menos = 50;

    for (i = 0; i < N; i++) {
        if (v[i] == v[i+1]) counter++;
        else {
            if (counter < menos) {
              menos = counter;
              r = v[i];
            } 
            counter = 1;
        }   
    }
    return r;
}

//31
int maisFreq (int v[], int N){
    int r = 0;
    int i = 0;
    int counter = 1;

    for (i = 0; i < N; i++) {
        if (v[i] < v[i+1]) counter++;
        else {
            if (counter > r) r = counter;
            counter = 1;
        }   
    }
    return r;
}

//32
int maxCresc (int v[], int N){
    int r = 0;
    int i = 0;
    int counter = 1;

    for (i = 0; i < N; i++) {
        if (v[i] <= v[i+1]) counter++;
        else {
            if (counter > r) r = counter;
            counter = 1;
        }   
    }
    return r;
}

//33
int elimRep (int v[], int N) {
    int i = 0;

    while (i < N) {
        int j;
        int rep = 0;
        for (j = 0; j < i; j++) {
            if (v[j] == v[i]) {
                rep = 1;
                break;
            }            
        }
        if (rep) {
            int k;
            for (k = i; k < N; k++) v[k] = v[k + 1];
            N--;
        }
        else i++;
    }
    return N;
}

//34
int elimRepOrd (int v[], int N) {
    int i;

    for (i = 0; i < N - 1; i++) {
        if (v[i] == v[i + 1]) {
            int j;
            for (j = i; j < N; j++) {
                v[j] = v[j + 1];
            }
            N--;
            i--;
        }
    }
    return N;
}

//35
int comunsOrd (int a[], int na, int b[], int nb){
    int r = 0;

    int ca = 0;
    int cb = 0;
    while (ca < na && cb < nb) {
        if (a[ca] == b[cb]) {
            r++;
            ca++;
            cb++;
        }
        else if(a[ca] > b[cb]) cb++;
        else ca++;
    }
    return r;
}

//36
int comuns (int a[], int na, int b[], int nb){
    int r = 0;
    
    int i, j;
    for (i = 0; i < na; i++) {
        for (j = 0; j < nb; j++) {
            if (a[i] == b[j]) {
                r++;
                break;
            }
        }
    }
    return r;
}

//37
int minInd (int v[], int n) {
    int r = 0;
    int i;
    for (i = 1; i < n; i++) 
        if (v[i] < v[r]) 
            r = i;
    return r;
}

//38
void somasAc (int v[], int Ac [], int N){

    int i;
    int acum = 0;
    for (i = 0; i < N; i++) {
        acum += v[i]; 
        Ac[i] = acum;
    }
}

//39
int triSup (int N, int m [N][N]) {
    int r = 1;
    int row, col;
    for (row = 1; row < N; row++) {
        for (col = 0; col < row; col++) {
            if (m[row][col] != 0) 
                return 0;
        }
    }
    return r;
}

//40
void transposta (int N, float m [N][N]) {
    int row, col;

    for (row = 0; row < N; row++) {
        for (col = 0; col < row; col++) {
            if (row != col) {
                float tmp = m[row][col];
                m[row][col] = m[col][row];
                m[col][row] = tmp;
            }
        }
    }
}

//41
void addTo(int N, int M, int a [N][M], int b[N][M]) {
    
    int row, col;

    for (row = 0; row < N; row++) {
        for (col = 0; col < M; col++) {
            a[row][col] = a[row][col] + b[row][col];
        }
    }
}





int main(int argc, char * argv[]) {

    //char * s;
    //strcpys(s, "ola");
    //printf("%s", s);

    //char * s = "mundo cruel!!!";
    //printf("iguaisConsecutivos: %d\n", iguaisConsecutivos(s));

    printf("trailingZ: %d\n", trailingZ(78791));


    return 0;
}