#include <stdio.h>
#include <stdlib.h>

struct Task {
        int low, high;
};

int partitionArray(int mas[], int, int);
void quickSort(int mas[], int);

int main() {
        int n;
        scanf("%d", & n);
        int mas[n];
        int i = 0;

        do {
                scanf("%d", & mas[i]);
        } while (++i < n);

        quickSort(mas, n);

        i = 0;
        do {
                printf("%d ", mas[i]);
        } while (++i < n);

        return 0;
}

int partitionArray(int mas[], int low, int high) {
        int pivot = mas[high];
        int i = low - 1, j = low;

        do {
                if (mas[j] < pivot) {
                        i++;
                        int hold = mas[i];
                        mas[i] = mas[j];
                        mas[j] = hold;
                }
        } while (++j <= high - 1);

        int hold = mas[i + 1];
        mas[i + 1] = mas[high];
        mas[high] = hold;

        return (i + 1);
}

void quickSort(int mas[], int n) {
        int top = -1;
        struct Task stack[n];

        stack[++top] = (struct Task) {
                .low = 0, .high = n - 1
        };

        do {
                struct Task task = stack[top--];
                int p = partitionArray(mas, task.low, task.high);

                if (p - 1 > task.low) {
                        stack[++top] = (struct Task) {
                                .low = task.low, .high = p - 1
                        };
                }
                if (p + 1 < task.high) {
                        stack[++top] = (struct Task) {
                                .low = p + 1, .high = task.high
                        };
                }
        } while (top >= 0);
}
