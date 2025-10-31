#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

void countSort(int arr[], int n, int exp) {
    int output[25], count[10] = {0};
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
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
        cout << "\nAfter sorting by digit " << exp << ": \n";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}

int main() {
    int data[] = {54321, 12345, 98765, 67890, 13579, 24680, 11111, 22222, 33333, 44444,
                  55555, 66666, 77777, 88888, 99999, 11223, 22334, 33445, 44556, 55667};
    int n = sizeof(data) / sizeof(data[0]);
    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl << endl;
    radixSort(data, n);
    cout << "\nAfter full sorting:\n";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
}
