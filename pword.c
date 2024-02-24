#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void buildArray(char * s, int lengthS, int * arr) {
        arr[0] = 0;
        int i = 1;
        do {
                int j = (i > 0) ? arr[i - 1] : 0;
                while (j > 0 && s[i] != s[j])
                        j = arr[j - 1];
                arr[i] = (s[i] == s[j]) ? ++j : j;
        } while (++i < lengthS);
}

int search_pat(char * s, char * t, int lengthS, int lengthT, int * arr) {

        for (int i = 0, index = 0; i < lengthT; i++) {
                index = (index == lengthS) ? arr[index - 1] : index;

                if (s[index] == t[i] && ++index) continue;

                bool slide = true;
                for (; index != 0 && s[index] != t[i]; index = arr[index - 1])
                        slide = false;

                i = (slide) ? i : i - 1;
                if (slide) {
                        return 0;
                }
        }
        return 1;
}

int main(int argc, char ** argv) {
        char * s = argv[1];
        char * t = argv[2];
        int lengthS = strlen(s), lengthT = strlen(t);
        int arr[lengthS];

        buildArray(s, lengthS, arr);

        if (search_pat(s, t, lengthS, lengthT, arr)) {
                printf("yes");
        } else {
                printf("no");
        }

        return 0;
}
