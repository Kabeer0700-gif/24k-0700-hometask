#include <iostream>
#include <cstdlib>
using namespace std;

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

void countSort(int arr[], int n, int exp) {
    int output[10], count[10] = {0};
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = findMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int data[] = {34, 78, 12, 90, 23, 56, 88, 45, 67, 10};
    int n = sizeof(data) / sizeof(data[0]);
    radixSort(data, n);
    cout << "Scores (ascending) and ranks:\n";
    for (int i = 0; i < n; i++)
        cout << "Rank " << i + 1 << ": " << data[i] << endl;
}
