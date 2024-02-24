#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revarray(void *base, size_t nel, size_t width);

int main() {
    long long arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    

    revarray(arr, 10, sizeof(int));


    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
  
    revarray(doubleArr, 5, sizeof(double));

    
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", doubleArr[i]);
    }
    printf("\n");

    return 0;
}

void revarray(void *base, size_t nel, size_t width) {
    void *newArray = malloc(nel * width);

    if (newArray == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    for (size_t i = 0; i < nel; ++i) {
        void *src = (char *)base + i * width;
        void *dst = (char *)newArray + (nel - i - 1) * width;
        memcpy(dst, src, width);
    }

    memcpy(base, newArray, nel * width);
    free(newArray);
}
