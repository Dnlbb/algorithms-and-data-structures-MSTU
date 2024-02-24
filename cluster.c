#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long max(long long a, long long b){
    return a>b?a:b;
}

struct{
    long long *heap;
    size_t size, fullness;
    long long time;
}typedef Queue;

void swap(Queue *q, int a, int b){
    long long temp = q->heap[a];
    q->heap[a] = q->heap[b];
    q->heap[b] = temp;
}

void heapify(Queue *q, int start){
    if (start<<1 > q->fullness)
        return;
    if ((start<<1) + 1 > q->fullness){
        if(q->heap[(start<<1) - 1] < q->heap[start - 1])
            swap(q, (start<<1) - 1, start - 1);
        return;
    }
    long long first = q->heap[(start<<1) - 1];
    long long second = q->heap[start<<1];
    if(first<q->heap[start - 1] && first < second){
        swap(q, start - 1, (start<<1) - 1);
        return heapify(q, start<<1);
    }
    if(second<q->heap[start - 1] && second <= first){
        swap(q, start - 1, start<<1);
        return heapify(q, (start<<1) + 1);
    }
}

long long getMin(Queue *q){
    swap(q, 0, (int)(--q->fullness));
    long long min = q->heap[q->fullness];
    heapify(q, 1);
    return min;
}

void normalize(Queue *q, int end){
    if(end <= 1)
        return;
    int p = end>>1;
    if(q->heap[p-1] > q->heap[end - 1]){
        swap(q, p - 1, end - 1);
        normalize(q, p);
    }
}

long long InitElem(){
    long long x;
    scanf("%lld", &x);
    return x;
}

void Enqueue(Queue *q){
    q->heap[q->fullness] = InitElem() + q->time;
    q->fullness++;
    normalize(q, (int)q->fullness);
}


Queue *InitQueue(){
    Queue *nq = malloc(sizeof(Queue));
    nq->time = 0;
    nq->fullness = 0;
    int n;
    scanf("%zd", &nq->size);
    scanf("%d", &n);
    nq->heap = malloc(nq->size * sizeof(long long ));
    for(int i = 0 ;i < n; i++){
        long long t1;
        scanf("%lld", &t1);
        if(nq->fullness == nq->size){
            nq->time = max(nq->time, getMin(nq));
        }
        nq->time = max(nq->time, t1);
        Enqueue(nq);
    }
    while (nq->fullness)
        nq->time = max(nq->time, getMin(nq));
    return nq;
}



int main(int argc, char** argv) {
    Queue *q = InitQueue();
    printf("%lld", q->time);
    free(q->heap);
    free(q);
    return 0;
}
