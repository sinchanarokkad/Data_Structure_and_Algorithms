#include <stdio.h>

void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int size = h - l + 1;
    int B[size];

    while (i <= mid && j <= h) {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= mid)
        B[k++] = A[i++];

    while (j <= h)
        B[k++] = A[j++];

    for (i = l; i <= h; i++)
        A[i] = B[i - l];
}

void MergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(A) / sizeof(A[0]);
    int i;

    MergeSort(A, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}
