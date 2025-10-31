#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

void countSort(int arr[], int n, int exp) {
    int output[50], count[10] = {0};
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
    int scores[50] = {
        56, 90, 34, 12, 78, 65, 99, 43, 80, 22,
        15, 67, 89, 45, 30, 70, 38, 95, 62, 20,
        87, 40, 77, 58, 61, 83, 25, 50, 46, 31,
        14, 68, 73, 60, 97, 33, 85, 48, 36, 17,
        10, 52, 18, 64, 81, 28, 75, 55, 24, 66
    };
    int n = 50;

    radixSort(scores, n);

    cout << "Scores (ascending) and ranks:\n";
    for (int i = 0; i < n; i++)
        cout << "Rank " << i + 1 << ": " << scores[i] << endl;

    return 0;
}
