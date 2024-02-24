#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * pr_f(char * );
void kmpmod(char * , char * );

int main(int argc, char * argv[]) {
        char * str2 = argv[1];
        char * str1 = argv[2];
        kmpmod(str1, str2);
        return 0;
}

int * pr_f(char * t) {
        int n = strlen(t);
        int * pi = malloc(n * sizeof(int));
        pi[0] = 0;
        for (int i = 1; i < n; i++) {
                int k = pi[i - 1];
                while (k > 0 && t[i] != t[k])
                        k = pi[k - 1];
                pi[i] = (t[i] == t[k]) ? ++k : k;
        }
        return pi;
}
void kmpmod(char * str, char * t) {
        int n = strlen(str), m = strlen(t), i = 0, j = 0;
        int * pi = pr_f(t);

        do {
                if (t[j] == str[i]) i++, j++;
                else j != 0 ? (j = pi[j - 1]) : (i++);

                if (j == m) printf("%d ", i - j);
        } while (i <= n);

        free(pi);
}
