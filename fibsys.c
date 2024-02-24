#include<stdio.h>

int main() {
        unsigned long long fibmas[90];
        long long x;
        int accum = 0;
        int nums[90] = {
                0
        };

        scanf("%lld", & x);
        if (x == 0) {
                printf("%d", 0);
                return 0;
        }

        fibmas[0] = 1;
        fibmas[1] = 2;
        for (int i = 2; i <= 90; i++)
                fibmas[i] = fibmas[i - 1] + fibmas[i - 2];

        for (int i = 0; i < 90; i++) {
                if (x == fibmas[i]) {
                        nums[i] = 1;
                        break;
                }
                if (fibmas[i] > x) {
                        x = x - fibmas[i - 1];
                        nums[i - 1] = 1;
                        i = 0;
                }
        }

        for (int i = 89; i >= 0; i--) {
                if (accum == 0 && nums[i - 1] == 1) {
                        accum = 1;
                        continue;
                }
                if (accum == 1)
                        printf("%d", nums[i]);
        }
        return 0;
}
