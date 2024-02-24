#include<stdio.h>

#include<string.h>

#include<stdlib.h>

void frame(int numh, int numw,
        const char * string) {
        int len = strlen(string);
        int point = 0;
        int horizontal_centering = (numw / 2) - (len / 2);

        if (numw <= 0 || numh <= 0) {
                printf("Usage: frame <height> <width> <text>");
                point = 1;
        }

        if (len >= (numw - 2)) {
                printf("Error");
                point = 1;
        }

        if (point == 0) {
                for (int i = 0; i < numw; i++) {
                        printf("*");
                }
                printf("\n");
                for (int i = 0; i < (numh - 2); i++) {
                        if (i == ((numh - 2) - 1) / 2) {
                                printf("*");
                                for (int k = 1; k < numw; k++) {
                                        if (k < (horizontal_centering - 1))
                                                printf(" ");
                                        if (k == (horizontal_centering - 1)) {
                                                printf("%s", string);
                                                k = k + len;
                                        }
                                        if (k > (horizontal_centering - 1) + len && k < numw)
                                                printf(" ");
                                }
                                printf("*");
                                printf("\n");
                                continue;
                        }
                        printf("*");
                        for (int j = 2; j <= numw; j++)
                                if (j == numw)
                                        printf("*\n");
                                else printf(" ");
                }
                for (int i = 0; i < numw; i++) {
                        printf("*");
                }
        }
}
int main() {
        int h, w;
        char * str;
        int point2 = 0;
        str = (char * ) malloc(100 * sizeof(char));
        if (str == NULL) {
                point2 = 1;
        }
        if (point2 == 0) {
                scanf("%d%d %[^\n]s", & h, & w, str);
                frame(h, w, str);
                free(str);
        }
        return 0;
}
