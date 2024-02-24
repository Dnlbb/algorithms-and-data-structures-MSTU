#include<stdio.h>

#include<limits.h>

int main() {
        long long point, maxel = LLONG_MIN, sumk = 0, k, i = 0, num;
        scanf("%lld", & num);
        long mas[num];
        long massumk[num];
        for (int p = 0; p < num; p++)
                scanf("%lld", & mas[p]);
        scanf("%lld", & k);
        point = k;
        for (int q = 0; q <= num - k; q++) {
                i = q;
                while (i < point) {
                        sumk = sumk + mas[i];
                        i++;
                        if (i - q == k) {
                                massumk[q] = sumk;
                                sumk = 0;
                        }
                }
                point++;
        }
        for (int q = 0; q <= num - k; q++) {
                if (maxel < massumk[q])
                        maxel = massumk[q];
        }
        printf("%lld", maxel);
        return 0;
}
