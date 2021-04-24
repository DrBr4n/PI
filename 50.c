#include <stdio.h>

char * strcpys(char * dest, char source[]) {

    char * result = source;

    for (int i = 0; source[i] != '\0'; i++)
    {
        printf("%c", source[i]);
        //*dest = source[i];
        //dest++;
    }
    
    return result;
}

int main(int argc, char * argv[]) {

    char * s;
    strcpys(s, "ola");
    printf("%s", s);

}