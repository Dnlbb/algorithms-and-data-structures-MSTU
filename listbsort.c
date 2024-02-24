#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *next;
    char *word;
};

struct {
    char *word;
    int i;
}typedef word;

struct Elem *InitElem(char *w, struct Elem *prev){
    struct Elem *new = malloc(sizeof(struct Elem));
    new->word = w;
    new->next = NULL;
    if(prev == NULL)
        return new;
    prev->next = new;
    return new;
}

int nextWord(char *s, word *w){
    while (s[w->i] == ' ' && s[w->i] != '\0' && s[w->i] != '\n'){
        w->i++;
    }
    if(s[w->i] == '\0' || s[w->i] == '\n')
        return 0;
    w->word = calloc(1000, sizeof(char));
    int k = 0;
    while (s[w->i] != ' ' && s[w->i] != '\0' && s[w->i] != '\n'){
        w->word[k++] = s[w->i++];
    }
    return 1;
}

struct Elem *InitList(){
    char s[1000];
    gets(s);
    struct Elem *nl = NULL;
    word *w = malloc(sizeof(word));
    w->i = 0;
    struct Elem *prev = NULL;
    while (nextWord(s, w)) {
        if (nl == NULL){
            nl = InitElem(w->word, NULL);
            prev = nl;
        }
        else{
            prev = InitElem(w->word, prev);
        }
    }
    free(w);
    return nl;
}

void swap(struct Elem *a, struct Elem *b){
    char *temp = a->word;
    a->word = b->word;
    b->word = temp;
}

struct Elem *bsort(struct Elem *list)
{
    struct Elem *end = NULL;
    while (end != list){
        struct Elem *step = list;
        while (step->next != end){
            if(strlen(step->word) > strlen(step->next->word))
                swap(step, step->next);
            step = step->next;
        }
        end =  step;
    }
    return list;
}


int main(int argc, char** argv) {
    struct Elem *list = InitList();
    list = bsort(list);
    while (list != NULL){
        printf("%s ", list->word);
        struct Elem *next = list->next;
        free(list->word);
        free(list);
        list = next;
    }
    return 0;
}
