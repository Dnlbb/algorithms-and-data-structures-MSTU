#include<stdio.h>

int main() {
        long long point = 0;
        long long mas1[8];
        long long mas2[8];
        int flagx[8] = {
                0
        };
        for (int i = 0; i < 8; i++)
                scanf("%lld", & mas1[i]);
        for (int i = 0; i < 8; i++)
                scanf("%lld", & mas2[i]);
        for (int i = 0; i < 8; i++)
                point = point + mas1[i] + mas2[i] + 1;
        for (int i = 0; i < 8; i++) {
                for (int k = 0; k < 8; k++) {
                        if (mas1[i] == mas2[k]) {
                                flagx[i] = 1;
                                mas2[k] = point;
                                break;
                        }
                }
        }
        for (int i = 0; i < 8; i++) {
                if (flagx[i] != 1) {
                        printf("no");
                        return 0;
                }
        }
        printf("yes");
        return 0;
}
