#include <stdio.h>

typedef unsigned int uint;
typedef struct {
    uint fromIndex;
    uint toIndex;
    int  sum;
} KadaneResponse;

KadaneResponse Kadane(int a[], uint n) {
    int partialSum = a[0], bestSum = a[0];
    uint from = 0, to = 0, i;

    for(i = 1; i < n; ++i) {
        if(a[i] > partialSum + a[i]) {
            partialSum = a[i];
            from = i;
        } else {
            partialSum += a[i];
        }

        if(partialSum >= bestSum) {
            bestSum = partialSum;
            to = i;
        }
    }

    KadaneResponse k;
    k.fromIndex = from;
    k.toIndex = to;
    k.sum = bestSum;
    return k;
}

int main() {
    uint n, i;
    scanf("%d", &n);

    int array[n];
    for(i = 0; i < n; i++) scanf("%d", &array[i]);

    KadaneResponse k = Kadane(array, n);

    printf("Sum: %d  From: %d  To: %d\n", k.sum, k.fromIndex, k.toIndex);

    return 0;
}
