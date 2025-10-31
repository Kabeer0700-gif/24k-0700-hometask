#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

void countSort(int arr[], int n, int exp) {
    int output[20], count[10] = {0};
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
    int maxVal = findMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int data[] = {2500, 1500, 1500, 3200, 450, 1200, 3000, 2500, 900};
    int n = sizeof(data) / sizeof(data[0]);
    radixSort(data, n);
    cout << "Sorted transactions:\n";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
}
