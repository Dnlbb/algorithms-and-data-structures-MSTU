#include<stdio.h>

#include<string.h>

#define SIZE 1000
int mass[SIZE] = {
        0
};
int wcount(char * s);
int main() {
        char s[SIZE];
        fgets(s, SIZE, stdin);
        int len = strlen(s);
        if (len > 0 && s[len - 1] == '\n') {
                s[len - 1] = '\0';
        }
        printf("%d", wcount(s));
        return 0;
}

int wcount(char * s) {
        int accum = 0;
        for (int i = 0; s[i] != '\0'; i++) {
                if (i == 0 && s[i] != ' ' || (i > 0 && s[i - 1] == ' ' && s[i] != ' '))
                        accum++;
        }
        return accum;
}
