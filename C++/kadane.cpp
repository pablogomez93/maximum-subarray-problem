#include <iostream>

using namespace std;

struct KadaneResponse {
    int fromIndex;
    int toIndex;
    int sum;

    KadaneResponse(int fromIndex, int toIndex, int sum) {
        this->fromIndex  = fromIndex;
        this->toIndex    = toIndex;
        this->sum        = sum;
    }
};

KadaneResponse Kadane(int a[], int n) {
    int partialSum = a[0], bestSum = a[0], from = 0, to = 0;

    for(int i = 1; i < n; ++i) {
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

    return KadaneResponse(from, to, bestSum);
}



int main() {
    int n;
    cin >> n;

    int array[n];
    for(int i = 0; i < n; i++) cin >> array[i];

    KadaneResponse k = Kadane(array, n);

    cout << "Sum: " << k.sum << "  From: " << k.fromIndex << "  To: " << k.toIndex << endl;

    return 0;
}
