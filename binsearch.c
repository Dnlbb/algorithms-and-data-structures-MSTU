#include <stdio.h>

int mass[25] = {1, 3, 5, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 28, 30, 35};
int element = 24;

int compare(unsigned long);

unsigned long binsearch(unsigned long, int (*)(unsigned long));

int main() {
    printf("%lu", binsearch(25, compare));
    return 0;
}

int compare(unsigned long i) {
    int q;
    if (mass[i] < element)
        q = -1; 
    else if (mass[i] == element)
        q = 0;
    else
        q = 1;
    return q;
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    int low = 0, high = nel - 1; 
    int middle;

    while (low <= high) {
        middle = (low + high) / 2;
        int comp_result = compare(middle);

        switch (comp_result) {
            case -1:
                low = middle + 1;
                break;
            case 0:
                return middle;
            case 1:
                high = middle - 1;
                break;
            default:
                return nel;
        }
    }

    return nel;
}
