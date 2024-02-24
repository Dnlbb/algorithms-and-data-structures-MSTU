#include <stdio.h>

struct Date {
        int Day, Month, Year;
};

void countsort(struct Date arr[], int n, int exp, int datePart);
void radixSort(struct Date arr[], int n);

int main() {
        int n;
        scanf("%d", & n);
        struct Date dates[n];
        for (int i = 0; i < n; i++) {
                scanf("%d %d %d", & dates[i].Year, & dates[i].Month, & dates[i].Day);
        }

        if (n == 1) {
                printf("%04d %02d %02d\n", dates[0].Year, dates[0].Month, dates[0].Day);
                return 0;
        }

        radixSort(dates, n);
        int i = 0;
        while (i < n) {
                printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
                i++;
        }

        return 0;
}

void countsort(struct Date mas[], int n, int exp, int dat) {
        struct Date output[n];
        int i, count[10] = {
                0
        };
        i = 0;
        while (i < n) {
                int dig;
                if (dat == 0)
                        dig = (mas[i].Day / exp) % 10;
                else if (dat == 1)
                        dig = (mas[i].Month / exp) % 10;
                else
                        dig = (mas[i].Year / exp) % 10;

                count[dig]++;
                i++;
        }

        i = 1;
        while (i < 10) {
                count[i] += count[i - 1];
                i++;
        }

        i = n - 1;
        while (i >= 0) {
                int dig;
                if (dat == 0)
                        dig = (mas[i].Day / exp) % 10;
                else if (dat == 1)
                        dig = (mas[i].Month / exp) % 10;
                else
                        dig = (mas[i].Year / exp) % 10;

                output[count[dig] - 1] = mas[i];
                count[dig]--;
                i--;
        }

        i = 0;
        while (i < n) {
                mas[i] = output[i];
                i++;
        }
}

void radixSort(struct Date mas[], int n) {
        int exp = 1;
        while (exp <= 10) {
                countsort(mas, n, exp, 0);
                exp *= 10;
        }
        exp = 1;
        while (exp <= 10) {
                countsort(mas, n, exp, 1);
                exp *= 10;
        }
        exp = 1;
        while (exp <= 1000) {
                countsort(mas, n, exp, 2);
                exp *= 10;
        }
}
