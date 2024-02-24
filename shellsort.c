#include<stdio.h>

long long mas[] = {2,231,21314,532,6324,-21213,1124,214,0,-123,1344};
unsigned long n = sizeof(mas) / sizeof(mas[0]);

void shellsort(unsigned long nel, int (*compare)(unsigned long i,unsigned long j),
         void (*swap)(unsigned long i, unsigned long j)) {
    unsigned long masd[30] = {1,2};
    int d = 0;
    for(int i = 2; i < 30; i++) {
        masd[i] = masd[i-1] + masd[i-2];
        if(masd[i] < nel){
            d = i;
        }
    }

    for (; d >= 0; d--) {
        unsigned long s = masd[d];
        for (unsigned long i = s; i < nel; ++i) {
            long j = i;
            while(j >= s && compare(j-s, j) != -1) {
                swap(j-s, j);
                if(j >= s){
                    j -= s;
                }
            }
        }
    }
}

void swap(unsigned long i, unsigned long  j){
    long hold = mas[i];
    mas[i] = mas[j];
    mas[j] = hold;
}

int compare(unsigned long i, unsigned long  j) {
    if (mas[i] > mas[j]) 
        return 1;
    if (mas[i] < mas[j])
        return -1;
    if (mas[i] == mas[j])
        return 0;
}

int main() {
    shellsort(n, compare, swap);
    for (unsigned long i = 0; i < n; ++i) {
        printf("%lld ", mas[i]);
    }
    return 0;
}
