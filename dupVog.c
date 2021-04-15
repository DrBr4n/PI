#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {

    int lenS = 0;
    for (int i = 0; argv[1][i] != '\0'; i++)
        lenS++;

    char * string = strdup(argv[1]);
    strcat(string, "          ");

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u') {
            lenS = lenS + 1;
            for (int k = lenS; k > i; k--) {
                string[k] = string[k-1];
            }
            i++;
        }
    }
    

    for (int i = 0; string[i] != '\0'; i++) {

        printf("%c", string[i]);
    }

    return 0;
}