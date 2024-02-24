#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct array {
    long long val;
    struct array *next;
}typedef array;

struct{
    array **heap;
    size_t size, fullness;
}typedef Queue;

void swap(Queue *q, int a, int b){
    array *temp = q->heap[a];
    q->heap[a] = q->heap[b];
    q->heap[b] = temp;
}

array *InitElem(){
    long long x;
    scanf("%lld", &x);
    array *na = malloc(sizeof(array));
    na->val = x;
    na->next = NULL;
    return na;
}

void heapify(Queue *q, int start){
    if (start<<1 > q->fullness)
        return;
    if ((start<<1) + 1 > q->fullness){
        if(q->heap[(start<<1) - 1]->val < q->heap[start - 1]->val)
            swap(q, (start<<1) - 1, start - 1);
        return;
    }
    long long first = q->heap[(start<<1) - 1]->val;
    long long second = q->heap[start<<1]->val;
    if(first<q->heap[start - 1]->val && first < second){
        swap(q, start - 1, (start<<1) - 1);
        return heapify(q, start<<1);
    }
    if(second<q->heap[start - 1]->val && second <= first){
        swap(q, start - 1, start<<1);
        return heapify(q, (start<<1) + 1);
    }
}

array *getMin(Queue *q){
    swap(q, 0, (int)(--q->fullness));
    array *min = q->heap[q->fullness];
    heapify(q, 1);
    return min;
}

void normalize(Queue *q, int end){
    if(end <= 1)
        return;
    int p = end>>1;
    if(q->heap[p-1]->val > q->heap[end - 1]->val){
        swap(q, p - 1, end - 1);
        normalize(q, p);
    }
}

void Enqueue(Queue *q, int len){
    q->heap[q->fullness] = NULL;
    if(len != 0)
        q->heap[q->fullness] = InitElem();
    array *end = q->heap[q->fullness];
    len--;
    while (len--) {
        end->next = InitElem();
        end = end->next;
    }
    q->fullness++;
    normalize(q, (int)q->fullness);
}

void pushEl(Queue *q, array *now){
    q->heap[q->fullness] = now;
    q->fullness++;
    normalize(q, (int)q->fullness);
}

Queue *InitQueue(){
    Queue *nq = malloc(sizeof(Queue));
    nq->fullness = 0;
    scanf("%zd", &nq->size);
    int *lengths;
    lengths = malloc(nq->size * sizeof(int));
    nq->heap = malloc(nq->size * sizeof(array *));
    for(int i = 0 ;i<nq->size; scanf("%d", &lengths[i++]));
    for(int i = 0 ;i < nq->size; Enqueue(nq, lengths[i++]));
    free(lengths);
    return nq;
}


array *mergeQueue(Queue *q){
    array *now = getMin(q);
    array *res = now;
    now = now->next;
    res->next = NULL;
    array *end = res;
    if(now != NULL)
        pushEl(q, now);
    while (q->fullness) {
        now = getMin(q);
        end->next = now;
        end = end->next;
        now = now->next;
        end->next = NULL;
        if(now != NULL)
            pushEl(q, now);
    }
    return res;
}

int main(int argc, char** argv) {
    Queue *q = InitQueue();
    array *res = mergeQueue(q);
    while (res != NULL){
        printf("%lld ", res->val);
        array *next = res->next;
        free(res);
        res = next;
    }
    free(q->heap);
    free(q);
    return 0;
}
