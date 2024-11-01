#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {

    int temp[r - l + 1];

    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int num = 0; num < r - l + 1; num++) {
        arr[l + num] = temp[num];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

