#include <stdio.h>
#include <stdlib.h>

void insertionsort(int * A, int);
void merge(int A[], int, int, int);
void mergesort(int A[], int, int);
int main() {
        int n;
        scanf("%d", &n);
        int mas[n];
        for (int g = 0; g < n; g++)
                scanf("%d", & mas[g]);
        mergesort(mas, 0, n - 1);
        for (int b = 0; b < n; b++)
                printf("%d  ", mas[b]);
        return 0;
}

void mergesort(int A[], int l, int r) {
        if (r - l < 5) {
                insertionsort(A + l, r - l + 1);
                return;
        }

        int mid = l + (r - l) / 2;
        mergesort(A, l, mid);
        mergesort(A, mid + 1, r);
        merge(A, l, mid, r);
}
void merge(int A[], int l, int mid, int r) {
        int x = mid - l + 1;
        int y = r - mid;
        int helpmas1[x], helpmas2[y];
        for (int i = 0; i < x; i++)
                helpmas1[i] = A[l + i];
        for (int i = 0; i < y; i++)
                helpmas2[i] = A[mid + 1 + i];

        int k = 0, p = 0, ind= l;
        while (k < x && p < y) {
                if (abs(helpmas1[k]) <= abs(helpmas2[p])) {
                        A[ind] = helpmas1[k];
                        k++;
                } else {
                        A[ind] = helpmas2[p];
                        p++;
                }
                ind++;
        }
        while (k < x) {
                A[ind] = helpmas1[k];
                k++;
                ind++;
        }
        while (p < y) {
                A[ind] = helpmas2[p];
                p++;
                ind++;
        }
}
void insertionsort(int * A, int n) {
        for (int i = 0; i < n; i++) {
                int hold = A[i];
                for (int j = i; j > 0 && abs(A[j - 1]) > abs(A[j]); j--) {
                        A[j] = A[j - 1];
                        A[j - 1] = hold;
                }
        }
}   
