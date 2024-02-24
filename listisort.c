#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

void swap(int a, int b) {
}

struct Elem *InitElem(int x, struct Elem *prev, struct Elem *next){
    struct Elem *new = malloc(sizeof(struct Elem));
    new->v = x;
    if(prev == NULL){
        new->next = new;
        new->prev = new;
        return new;
    }
    prev->next = new;
    next->prev = new;
    new->next = next;
    new->prev = prev;
    return new;
}

void InsertElem(struct Elem *new, struct Elem *prev, struct Elem *next){
    prev->next = new;
    next->prev = new;
    new->next = next;
    new->prev = prev;
}

struct Elem *InitList(int len){
    int x;
    struct Elem *nl = NULL;
    while (len--){
        scanf("%d", &x);
        if(nl == NULL){
            nl = InitElem(x, NULL, NULL);
        }else{
            InitElem(x, nl->prev, nl);
        }
    }
    return nl;
}

struct Elem *pop(struct Elem *shambolic){
    if(shambolic->next == shambolic)
        return NULL;
    struct Elem *next = shambolic->next;
    next->prev = shambolic->prev;
    shambolic->prev->next = next;
    shambolic->prev = NULL;
    shambolic->next = NULL;
    return next;
}

struct Elem *insert(struct Elem *sorted, struct Elem *x){
    if(sorted == NULL){
        x->prev = x;
        x->next = x;
        return x;
    }
    struct Elem *now = sorted->prev;
    while (now != sorted && now->v > x->v){
        now = now->prev;
    }
    if(now->v <= x->v){
        InsertElem(x, now, now->next);
        return sorted;
    }else{
        InsertElem(x, now->prev, now);
        return x;
    }

}

struct Elem *sortilist(struct Elem *shambolic){
    struct Elem *sorted = NULL;
    while (shambolic != NULL){
        struct Elem* now = shambolic;
        shambolic = pop(shambolic);
        sorted = insert(sorted, now);
    }
    return sorted;
}


int main(int argc, char** argv) {
    int len;
    scanf("%d", &len);
    struct Elem *list = InitList(len);
    list = sortilist(list);
    while (len--){
        printf("%d ", list->v);
        struct Elem *next;
        if(len == 0){
            next = NULL;
        }else{
            next = list->next;
        }
        free(list);
        list = next;
    }
    return 0;
}
