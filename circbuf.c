#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENQ() \
if (equal(action, "ENQ")){ \
    Enqueue(q);          \
    continue;\
}

#define EMPTY() \
if (equal(action, "EMPTY")){ \
    QueueEmpty(q);          \
    continue;\
}

#define DEQ() \
if (equal(action, "DEQ")){ \
    Dequeue(q);          \
    continue;\
}

#define release() \
free(action);      \
free(q->buf);     \
free(q);

struct{
    long long *buf;
    size_t first, last, size, fullness;
}typedef Queue;

struct {
    char action[10];
}typedef act;

act *InitAct(){
    act *na = malloc(sizeof(act));
    return na;
}

Queue *InitQueue(){
    Queue *nq = malloc(sizeof(Queue));
    nq->first = 0;
    nq->last = 0;
    nq->buf = calloc(4, sizeof(long long));
    nq->size = 4;
    nq->fullness = 0;
    return nq;
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

void expand(Queue *q){
    long long *extended = calloc(q->size << 1, sizeof(long long));
    for(int i = 0; i < q->fullness; i++, q->first = (q->first + 1) % q->size)
        extended[i] = q->buf[q->first];
    free(q->buf);
    q->buf = extended;
    q->last = q->fullness;
    q->size <<= 1;
    q->first = 0;
}

void Enqueue(Queue *q){
    long long x;
    scanf("%lld", &x);
    if(!(q->fullness - q->size))
        expand(q);
    q->buf[q->last] = x;
    ++q->fullness;
    q->last = (q->last + 1) % q->size;
}

void QueueEmpty(Queue *q){
    if(q->fullness == 0)
        return (void)printf("true\n");
    printf("false\n");
}

void Dequeue(Queue *q){
    printf("%lld\n", q->buf[q->first]);
    q->fullness--;
    q->first = (q->first + 1) % (q->size);
}

int main(int argc, char** argv) {
    Queue *q = InitQueue();
    act *action = InitAct();
    while (nextAct(action)){
        ENQ()
        EMPTY()
        DEQ()
    }
    release()
    return 0;
}
