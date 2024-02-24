#include <stdio.h>

#define SIZE 1000000
int main() {
        char mas[SIZE];
        scanf("%s", & mas);
        int help_mas[26] = {0};
        for (int i = 0; mas[i] != '\0'; i++) {
                help_mas[mas[i] - 97]++;

        }
        for (int i = 0, n = 0; i < 26; i++) {
                for (int j = 0; j < help_mas[i]; j++) {
                        mas[n] = i + 97;
                        n++;
                }
        }
        printf("%s", mas);
        return 0;
}
