#include <stdio.h>

int compare(void * , void * );
int maxarray(void * , size_t, size_t, int( * )(void * , void * ));
int main() {
        int mas[5] = {1000, 763129, 10, 100, 76879};
        size_t x = maxarray(mas, 5, sizeof(int), compare);
        printf("%lu", x);
        return 0;
}

int compare(void * a, void * b) {
        int res;
        int A = * (int * ) a;
        int B = * (int * ) b;

        if (A > B)
                res = 1;
        else if (A == B)
                res = 0;
        else
                res = -1;
        return res;
}

int maxarray(void * base, size_t nel, size_t width, int( * compare)(void * a, void * b)) {
        if (nel <= 0 || base == NULL)
                return -1;
        size_t curmax = 0;
        for (size_t i = 1; i < nel; i++) {
                int q = compare((char * ) base + (i * width), (char * ) base + (curmax * width));
                if (q > 0) {
                        curmax = i;
                }
        }

        return curmax;
}
