#include <stdio.h>
#include <stdlib.h>

void one() {

    int max = -1;
    int c = -1;
    while (c != 0) {
        scanf("%d", &c);
        if (c > max) max = c;
    }

    printf("Max: %d\n", max);
}

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
int difConsecutivos(char s[]) {
    int max = 0;
    int counter = 1;
    int i;
+
    return max;
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

int elemStr(char * s, int i, int n) {
    int r = 0;
    for(; i < n; i++) {
        if (s[i] == s[n]) return 1;
    }
    return r;
}

//16
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
    if (na >= nb) {
        int n = na;
        int z = nb;
    } else {
        int n = nb;
        int z = na;
    } 

    int c = 0;
    int i = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == b[c]) {
            r++;
            c++;
        }
        else if(a[i] > b[c]) {
            c++;
            i--;
        }
    }
    return r;
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