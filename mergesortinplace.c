#include <stdio.h>

void merge(int a[], int b[], int m, int n) {
    int i = n - 1, j = m - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] > b[j]) {
            a[k--] = a[i--];
        } else {
            a[k--] = b[j--];
        }
    }
    while (j >= 0) {
        a[k--] = b[j--];
    }
}

int main() {
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8, 10};
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    merge(a, b, m, n);

    for (int i = 0; i < m + n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
