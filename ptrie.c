#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSERT() \
if (equal(action, "INSERT")){ \
    insert(b);          \
    continue;\
}

#define DELETE() \
if (equal(action, "DELETE")){ \
    delete(b);          \
    continue;\
}

#define PREFIX() \
if (equal(action, "PREFIX")){ \
    prefix(b);          \
    continue;\
}

#define release() \
free(action);      \
rel(b);

struct bor{
    struct bor *next[300];
    int count;
    int word;
}typedef bor;

struct {
    char action[10];
}typedef act;

act *InitAct(){
    act *na = malloc(sizeof(act));
    return na;
}

void rel(bor *b){
    for(int i = 0 ; i < 300; i++)
        if(b->next[i]!=NULL)
            rel(b->next[i]);
    free(b);
}

bor *InitBor(){
    bor *nb = malloc(sizeof(bor));
    for(int i = 0; i < 300; i++){
        nb->next[i] = NULL;
    }
    nb->count = 0;
    nb->word = 0;
    return nb;
}

int equal(act *f, char *s){
    if(strcmp(f->action, s) == 0)
        return 1;
    return 0;
}

int nextAct(act *action){
    scanf("%s", action->action);
    if(equal(action, "END"))
        return 0;
    return 1;
}

int was_word(bor *b, char *word){
    int i = 0;
    while(word[i] != '\0' && word[i] != '\n'){
        if(b->next[word[i]] == NULL){
            return 0;
        }
        b = b->next[word[i]];
        i++;
    }
    return b->word;
}

void insert(bor *b){
    char *word = calloc(100000, sizeof(char));
    scanf("%s", word);
    if(was_word(b, word)){
        free(word);
        return;
    }
    int i = 0;
    while(word[i] != '\0' && word[i] != '\n'){
        if(b->next[word[i]] == NULL){
            b->next[word[i]] = InitBor();
        }
        b = b->next[word[i]];
        b->count++;
        i++;
    }
    b->word = 1;
    free(word);
}

void delete(bor *b){
    int i = 0;
    char *word = calloc(100000, sizeof(char));
    scanf("%s", word);
    while(word[i] != '\0' && word[i] != '\n'){
        b = b->next[word[i]];
        b->count--;
        i++;
    }
    b->word = 0;
    free(word);
}

void prefix(bor *b){
    int i = 0;
    char *word = calloc(100000, sizeof(char));
    scanf("%s", word);
    while(word[i] != '\0' && word[i] != '\n'){
        if(b->next[word[i]] == NULL){
            printf("%d\n", 0);
            free(word);
            return;
        }
        b = b->next[word[i]];
        i++;
    }
    printf("%d\n", b->count);
    free(word);
}

int main(int argc, char** argv) {
    bor *b = InitBor();
    act *action = InitAct();
    while (nextAct(action)){
        DELETE()
        PREFIX()
        INSERT()
    }
    release()
    return 0;
}
