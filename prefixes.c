#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void p_prefix(char * s) {
        int n = strlen(s);
        int * pi = pr_f(s);
        int * seen_p = calloc(n + 1, sizeof(int));

        for (int i = 1; i <= n; i++) {
                int len = i, p = len - pi[i - 1], k = len / p, m = len % p == 0, b = k > 1, nsb = !seen_p[len];
                if (m && b) {
                        if (nsb) {
                                printf("%d %d\n", len, k);
                                seen_p[len] = 1;
                        } else {

                                continue;
                        }
                } else {

                        continue;
                }
        }

        free(pi);
        free(seen_p);
}
int main(int argc, char * argv[]) {
        char * s = argv[1];
        p_prefix(s);
        return 0;
}
