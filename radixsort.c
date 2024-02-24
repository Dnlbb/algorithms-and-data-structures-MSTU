#include <stdio.h>
#include <stdlib.h>

union Int32 {
        int x;
        unsigned char bytes[4];
};

void cSort(union Int32 mas[], int, int);
void radixSort(union Int32 arr[], int);
void modRadixSort(union Int32 mas[], int);

int main() {
        int n;
        scanf("%d", & n);
        union Int32 arr[n];

        for (int i = 0; i < n; i++) {
                scanf("%d", & arr[i].x);
        }

        modRadixSort(arr, n);

        for (int i = 0; i < n; i++) {
                printf("%d ", arr[i].x);
        }

        return 0;
}

void cSort(union Int32 mas[], int size, int ind) {
        int res[size];
        int cnt[256] = {0};
        int i;

        for (i = 0; i < size; i++) {
                cnt[mas[i].bytes[ind]]++;
        }

        for (i = 1; i < 256; i++) {
                cnt[i] += cnt[i - 1];
        }

        for (i = size - 1; i >= 0; i--) {
                res[cnt[mas[i].bytes[ind]] - 1] = mas[i].x;
                cnt[mas[i].bytes[ind]]--;
        }

        for (i = 0; i < size; i++) {
                mas[i].x = res[i];
        }
}

void radixSort(union Int32 arr[], int size) {

        for (int i = 0; i < 4; i++) {
                cSort(arr, size, i);
        }
}

void modRadixSort(union Int32 mas[], int size) {
        union Int32 positive[size], negative[size];
        int pos = 0, neg = 0;

        for (int i = 0; i < size; i++) {
                if (mas[i].x >= 0) {
                        positive[pos++] = mas[i];
                } else {
                        negative[neg++] = mas[i];
                }
        }

        radixSort(positive, pos);
        radixSort(negative, neg);

        int ind = 0;
        for (int i = 0; i < neg; i++) {
                mas[ind++] = negative[i];
        }
        for (int i = 0; i < pos; i++) {
                mas[ind++] = positive[i];
        }
}
