#include <stdio.h>


void Kadane_mod(double mas[], int nel) {
        int l = 0, r = 0, start = 0;
        double maxpr = mas[0], pr = mas[0];
        int i = 0;
        while (i < nel) {
                pr *= mas[i];
                if (pr > maxpr) {
                        maxpr = pr;
                        l = start;
                        r = i;
                }
                if (pr < 1) {
                        pr = 1;
                        start = i + 1;
                }
                i++;
        }
        printf("%d %d", l, r);
}

int main() {
        int nel;
        scanf("%d", & nel);
        double mas[nel];
        for (int i = 0; i < nel; i++) {
                double a, b;
                scanf("%lf%c%lf", &a, &b, &b);
                mas[i] = a / b;
        }
        Kadane_mod(mas, nel);
        return 0;
}
