#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) a > b ? a : b

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

#define MAX() \
if (equal(action, "MAX")){ \
    Maximum(q);          \
    continue;\
}

#define release() \
free(action);      \
free(q->stack1);  \
free(q->stackMax1);\
free(q->stack2);  \
free(q->stackMax2);\
free(q);

struct{
    long long *stack1;
    long long *stack2;
    long long *stackMax1;
    long long *stackMax2;
    size_t size1, size2, fullness, fullness1, fullness2;
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
    nq->stack1 = calloc(4, sizeof(long long));
    nq->stack2 = calloc(4, sizeof(long long));
    nq->stackMax1 = calloc(4, sizeof(long long));
    nq->stackMax2 = calloc(4, sizeof(long long));
    nq->size1 = 4;
    nq->size2 = 4;
    nq->fullness = 0;
    nq->fullness1 = 0;
    nq->fullness2 = 0;
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

void expand1(Queue *q){
    long long *extended = calloc(q->size1 << 1, sizeof(long long));
    long long *extendedMax = calloc(q->size1 << 1, sizeof(long long));
    for(int i = 0; i < q->fullness1; i++) {
        extended[i] = q->stack1[i];
        extendedMax[i] = q->stackMax1[i];
    }
    free(q->stack1);
    free(q->stackMax1);
    q->stack1 = extended;
    q->stackMax1 = extendedMax;
    q->size1 <<= 1;
}

void expand2(Queue *q){
    long long *extended = calloc(q->size2 << 1, sizeof(long long));
    long long *extendedMax = calloc(q->size2 << 1, sizeof(long long));
    for(int i = 0; i < q->fullness2; i++) {
        extended[i] = q->stack2[i];
        extendedMax[i] = q->stackMax2[i];
    }
    free(q->stack2);
    free(q->stackMax2);
    q->stack2 = extended;
    q->stackMax2 = extendedMax;
    q->size2 <<= 1;
}

void Enqueue(Queue *q){
    long long x;
    scanf("%lld", &x);
    if(!(q->fullness1 - q->size1))
        expand1(q);
    if(q->fullness1 == 0)
        q->stackMax1[q->fullness1] = x;
    else
        q->stackMax1[q->fullness1] = max(x, q->stackMax1[q->fullness1 - 1]);
    q->stack1[q->fullness1++] = x;
    ++q->fullness;
}

void QueueEmpty(Queue *q){
    if(q->fullness == 0)
        return (void)printf("true\n");
    printf("false\n");
}

long long pop1(Queue *q){
    q->fullness1--;
    return q->stack1[q->fullness1];
}

void push2(Queue *q, long long val){
    if (!(q->fullness2 - q->size2))
        expand2(q);
    if(q->fullness2 == 0)
        q->stackMax2[q->fullness2] = val;
    else
        q->stackMax2[q->fullness2] = max(val, q->stackMax2[q->fullness2 - 1]);
    q->stack2[q->fullness2++] = val;
}

void transfer(Queue *q){
    while (q->fullness1)
        push2(q, pop1(q));
}

void Dequeue(Queue *q){
    if(q->fullness2 == 0)
        transfer(q);
    printf("%lld\n", q->stack2[--q->fullness2]);
    q->fullness--;
}

void Maximum(Queue *q){
    if(q->fullness1 == 0)
        return (void)printf("%lld\n", q->stackMax2[q->fullness2 - 1]);
    if(q->fullness2 == 0)
        return (void)printf("%lld\n", q->stackMax1[q->fullness1 - 1]);
    printf("%lld\n", max(q->stackMax1[q->fullness1 - 1], q->stackMax2[q->fullness2 - 1]));
}

int main(int argc, char** argv) {
    Queue *q = InitQueue();
    act *action = InitAct();
    while (nextAct(action)){
        ENQ()
        EMPTY()
        DEQ()
        MAX()
    }
    release()
    return 0;
}
