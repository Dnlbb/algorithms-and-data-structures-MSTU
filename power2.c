#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int powertwo(long long mas[], int size);

int main() {
    int n;
    scanf("%d", &n);
    long long seq[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &seq[i]);
    }

    int count = powertwo(seq, n);
    printf("%d", count);

    return 0;
}


int powertwo(long long mas[], int size) {
    int count = 0;

    for (int i = 1; i < (1 << size); i++) {
        long long sum = 0;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {
                sum += mas[j];
            }
        }
        if (sum > 0 && (sum & (sum - 1)) == 0) {
            count++;
        }
    }

    return count;
}
