#include<stdio.h>

int main() {
        int n;
        long long x0;
        scanf("%d", & n);
        long long mas[n + 1];
        long long masmean[n + 1];
        scanf("%lld", & x0);
        for (int i = 0; i <= n; i++)
                scanf("%lld", & mas[i]);
        masmean[0] = mas[0];
        for (int i = 1; i <= n; i++)
                masmean[i] = (x0 * masmean[i - 1]) + mas[i];
        printf("%lld", masmean[n]);
        printf("\n");
        for (int i = 0, k = n; i <= n; i++, k--)
                mas[i] = k * mas[i];
        masmean[0] = mas[0];
        for (int i = 1; i <= n - 1; i++)
                masmean[i] = (x0 * masmean[i - 1]) + mas[i];
        printf("%lld", masmean[n - 1]);
        return 0;
}
