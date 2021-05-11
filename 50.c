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

int bitsUm(unsigned int n) {
    int r = 0;
    while (n) {
        r+= (n % 2);
        n = n / 2;
    }
    return r;
}

int trailingZ (unsigned int n) {

    if (n % 2) return 0;
    else return 1 + trailingZ(n/2);
}

int qDig(unsigned int n) {
    int r = 1;
    while (n > 9) {
        n = n / 10;
        r++;
    }
    return r;
}

char * strcats(char s1[], char s2[]) {

    char * res = s1;

    for (int i = 0; s1[i] != '\0'; i++) res++;

    for (int i = 0; s2[i] != '\0'; i++) {
        *res = s2[i];
        res++;
    }
    
    return res;
}


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

int main(int argc, char * argv[]) {

    //char * s;
    //strcpys(s, "ola");
    //printf("%s", s);

    char * s = strcats("Ola", "tudo bem");
    printf("%s", s);

    return 0;
}