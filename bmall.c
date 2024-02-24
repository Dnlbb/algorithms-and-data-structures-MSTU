#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ALPHABET_SIZE 94

int charToIndex(char c) {
    return (int) c - 32;
}

int * suffix(char str[]) {
    int n = strlen(str);
    int * sigma1 = calloc(n, sizeof(int));
    int t = n - 1;
    sigma1[n - 1] = t;
    int i = n - 2;
    while (i >= 0) {
        while (t < n - 1 && str[t] != str[i]) {
            t = sigma1[t + 1];
        }
        if (str[t] == str[i]) {
            t = t - 1;
        }
        sigma1[i] = t;
        i = i - 1;
    }
    return sigma1;
}

int * delta2(char str[]) {
    int n = strlen(str);
    int * del2 = calloc(n, sizeof(int));
    int * sigma1 = suffix(str);
    int i = 0, t = sigma1[0];
    while (i < n) {
        while (t < i) {
            t = sigma1[t + 1];
        }
        del2[i] = -i + t + n;
        i = i + 1;
    }
    i = 0;
    while (i < n - 1) {
        t = i;
        while (t < n - 1) {
            t = sigma1[t + 1];
            if (str[i] != str[t])
                del2[t] = -(i + 1) + n;
        }
        i = i + 1;
    }
    free(sigma1);
    return del2;
}

int * delta1(char str[]) {
    int n = strlen(str);
    int * del1 = calloc(ALPHABET_SIZE, sizeof(int));
    int a = 0;
    while (a < ALPHABET_SIZE) {
        del1[a] = n;
        a = a + 1;
    }
    int j = 0;
    while (j < n) {
        int index = charToIndex(str[j]);
        if (index >= 0 && index < ALPHABET_SIZE) {
            del1[index] = n - j - 1;
        }
        j = j + 1;
    }
    return del1;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void BMS(char str[], char T[]) {
    int * del1 = delta1(str);
    int * del2 = delta2(str);
    int n = strlen(str), n_t = strlen(T), k = n - 1;

    while (k < n_t) {
        int i = n - 1;
        while (i >= 0 && k < n_t && T[k] == str[i]) {
            if (i == 0) {
                printf("%d ", k);
                break;
            }
            i--;
            k--;
        }

        if (i > 0) {
            int index = charToIndex(T[k]);
            if (index >= 0 && index < ALPHABET_SIZE) {
                k += max(del1[index], del2[i]);
            } else {
                k += n;
            }
        } else {
            k += n;
        }
    }

    free(del1);
    free(del2);
}

int main(int argc, char * argv[]) {
    char * pat = argv[1];
    char * text = argv[2];
    int alphabet_size = 94;
    BMS(pat, text);
    return 0;
}
