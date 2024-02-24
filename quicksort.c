#include<stdio.h>
void swap(int mas[], unsigned long , unsigned long ); 
void SelectionSort(int mas[], int , int );
void QuickSort(int mas[], int , int , int );

int main() {
        int n, m;
        scanf("%d %d", &n, &m);
        int a[n];
        for (int i = 0; i < n; i++) {
                scanf("%d", & a[i]);
        }
        QuickSort(a, 0, n - 1, m);
        for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
        }
        return 0;
}

void swap(int mas[], unsigned long i, unsigned long j) {
        int hold;
        hold = mas[i];
        mas[i] = mas[j];
        mas[j] = hold;
}
void SelectionSort(int mas[], int s, int e) {
        int min;
        for (int i = s; i < e; i++) {
                min = i;
                for (int j = i + 1; j <= e; j++) {
                        if (mas[j] < mas[min]) {
                                min = j;
                        }
                }
                swap(mas, min, i);
        }
}
void QuickSort(int mas[], int s, int e, int m) {
    if (m == 1) {
        if (s < e) {
            int i = s - 1, j = e + 1;
            int a = mas[(s + e) / 2];
            for (;;) {
                for (i++; mas[i] < a; i++);
                for (j--; mas[j] > a; j--);
                if (i >= j)
                    break;
                swap(mas, i, j);
            }
            QuickSort(mas, s, j, m);
            QuickSort(mas, j + 1, e, m);
        }
    } else {
        if (e - s < m)
            SelectionSort(mas, s, e);
        if (s < e) {
            int i = s - 1, j = e + 1;
            int a = mas[(s + e) / 2];
            for (;;) {
                for (i++; mas[i] < a; i++);
                for (j--; mas[j] > a; j--);
                if (i >= j)
                    break;
                swap(mas, i, j);
            }
            if ((e - i + 1) <= m)
                SelectionSort(mas, i, e);
            else
                QuickSort(mas, i, e, m);
            if ((j - s + 1) <= m)
                SelectionSort(mas, s, j);
            else
                QuickSort(mas, s, j, m);
        }
    }
}
