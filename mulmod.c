#include<stdio.h>

int main() {
        unsigned long long a, b, m;
        unsigned long long n = 0;
        unsigned long long res;
        unsigned long long mas[300];
        unsigned long long revmas[300];
        unsigned long long masmean[300];
                scanf("%lld", & a);
                scanf("%lld", & b);
                scanf("%lld", & m);
        for (long long i = 0; b != 0; i++) {
                mas[i] = b % 2;
                b = b / 2;
                n++;
        }
        for (unsigned long long i = 1; i <= n; i++)
                revmas[i - 1] = mas[n - i];
        masmean[0] = revmas[0] * 2;
        masmean[1] = ((a * masmean[0]) % m + (a * revmas[1]) % m) % m;
        for (unsigned long long i = 2; i < n; i++)
                masmean[i] = ((2 * masmean[i - 1]) % m + (a * revmas[i]) % m) % m;
        printf("%lld", masmean[n - 1]);
        return 0;
}
