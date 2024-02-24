#include<stdio.h>

void print_intersectionAB(int number) {
        for (int i = 0; i < 32; i++) {
                if ((number & (1 << i)) != 0)
                        printf("%d  ", i);
        }
}
int main() {
        int A = 0, B = 0, numA, numB, a = 0, b = 0;
        scanf("%d", & numA);
        for (int i = 0; i < numA; i++) {
                scanf("%d", & a);
                A |= (1 << a);
        }
        scanf("%d", & numB);
        for (int i = 0; i < numB; i++) {
                scanf("%d", & b);
                B |= (1 << b);
        }
        int intersectionAB = A & B;
        print_intersectionAB(intersectionAB);
        return 0;
}
