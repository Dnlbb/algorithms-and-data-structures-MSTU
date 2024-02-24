#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void * a, const void * b);
void swap(void * a, void * b, size_t width);
void heapify(void * base, size_t nel, size_t width, int( * compare)(const void * a,const void * b), int root);
void hsort(void * base, size_t nel, size_t width, int( * compare)(const void * a,const void * b));

int main() {
        int n;
        scanf("%d", &n);
        
        if (n == 1) {
        char *word = (char *)malloc(1000 * sizeof(char));
        scanf("%s", word);
        printf("%s\n", word);
        free(word);
        return 0;
        }

        char ** arr = (char ** ) malloc(n * sizeof(char * ));
        int i = 0;
        do {
                arr[i] = (char * ) malloc(1000 * sizeof(char));
                scanf("%s", arr[i]);
        } while (++i < n);
        
        hsort(arr, n, sizeof(char * ), compare_strings);

        i = 0;
        do {
                printf("%s\n", arr[i]);
                free(arr[i]);
        } while (++i < n);

        free(arr);
        return 0;
}

int compare_strings(const void * a,
        const void * b) {
        const char * s1 = * (const char ** ) a;
        const char * s2 = * (const char ** ) b;
        int c1 = 0, c2 = 0;

        while ( * s1) {
                c1 += ( * s1++ == 'a') ? 1 : 0;
        }

        while ( * s2) {
                c2 += ( * s2++ == 'a') ? 1 : 0;
        }

        return c1 - c2;
}

void swap(void * a, void * b, size_t width) {
        char * temp = malloc(width);
        memcpy(temp, a, width);
        memcpy(a, b, width);
        memcpy(b, temp, width);
        free(temp);
}

void heapify(void * base, size_t nel, size_t width, int( * compare)(const void * a,
        const void * b), int root) {
        char * arr = (char * ) base;
        int largest = root;
        int left, right;

        do {
                left = 2 * root + 1;
                right = 2 * root + 2;

                largest = (left < nel && compare( & arr[left * width], & arr[largest * width]) > 0) ? left : largest;
                largest = (right < nel && compare( & arr[right * width], & arr[largest * width]) > 0) ? right : largest;

                if (largest != root) {
                        swap( & arr[root * width], & arr[largest * width], width);
                        root = largest;
                } else {
                        break;
                }
        } while (1);
}

void hsort(void * base, size_t nel, size_t width, int( * compare)(const void * a,
        const void * b)) {
         if (nel <= 1) {
        return; 
        }
        char * arr = (char * ) base;

        int i = nel / 2 - 1;
        do {
                heapify(arr, nel, width, compare, i);
        } while (--i >= 0);

        i = nel - 1;
        do {
                swap(arr, & arr[i * width], width);
                heapify(arr, i, width, compare, 0);
        } while (--i > 0);
}
