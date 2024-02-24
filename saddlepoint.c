#include<stdio.h>

void findSaddlePoint(int high, int width, int mas[high][width]);
int main() {
        int high, width;
        scanf("%d %d", & high, & width);
        int mas[high][width];

        for (int i = 0; i < high; i++) {
                for (int j = 0; j < width; j++) {

                        scanf("%d", & mas[i][j]);
                }
        }

        findSaddlePoint(high, width, mas);

        return 0;
}

void findSaddlePoint(int high, int width, int mas[high][width]) {
        int maxInRow[high], minInCol[width];

        for (int i = 0; i < high; ++i) {
                maxInRow[i] = mas[i][0];
        }

        for (int j = 0; j < width; ++j) {
                minInCol[j] = mas[0][j];
        }

        for (int i = 0; i < high; i++) {
                for (int j = 0; j < width; j++) {
                        if (mas[i][j] > maxInRow[i]) {
                                maxInRow[i] = mas[i][j];
                        }
                }
        }

        for (int j = 0; j < width; j++) {
                for (int i = 0; i < high; i++) {
                        if (mas[i][j] < minInCol[j]) {
                                minInCol[j] = mas[i][j];
                        }
                }
        }

        int isSaddleExist = 0;

        for (int i = 0; i < high; i++) {
                for (int j = 0; j < width; j++) {
                        if (maxInRow[i] == minInCol[j]) {
                                printf("%d %d", i, j);
                                isSaddleExist = 1;
                        }
                }
        }

        if (isSaddleExist == 0)
                printf("none\n");
}
