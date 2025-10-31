#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int comparisonCount;

int partitionArray(int arr[], int left, int right, int pivotIndex) {
    swap(arr[pivotIndex], arr[right]);
    int pivotValue = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        comparisonCount++;
        if (arr[j] < pivotValue)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right, int pivotType) {
    if (left >= right) return;
    int pivotIndex;
    if (pivotType == 1) pivotIndex = left;
    else if (pivotType == 2) pivotIndex = left + rand() % (right - left + 1);
    else if (pivotType == 3) pivotIndex = (left + right) / 2;
    else {
        int mid = (left + right) / 2;
        int first = arr[left], middle = arr[mid], last = arr[right];
        int medianValue;
        if ((first <= middle && middle <= last) || (last <= middle && middle <= first))
            medianValue = mid;
        else if ((middle <= first && first <= last) || (last <= first && first <= middle))
            medianValue = left;
        else
            medianValue = right;
        pivotIndex = medianValue;
    }
    int partitionIndex = partitionArray(arr, left, right, pivotIndex);
    quickSort(arr, left, partitionIndex - 1, pivotType);
    quickSort(arr, partitionIndex + 1, right, pivotType);
}

int main() {
    srand(time(0));
    int baseArray[] = {10, 7, 8, 9, 1, 5, 3, 6, 2, 4};
    const int size = sizeof(baseArray) / sizeof(baseArray[0]);
    int arr1[size], arr2[size], arr3[size], arr4[size];
    for (int i = 0; i < size; i++) {
        arr1[i] = baseArray[i];
        arr2[i] = baseArray[i];
        arr3[i] = baseArray[i];
        arr4[i] = baseArray[i];
    }
    comparisonCount = 0;
    quickSort(arr1, 0, size - 1, 1);
    cout << "Pivot Type 1 (First Element) Comparisons: " << comparisonCount << endl;
    comparisonCount = 0;
    quickSort(arr2, 0, size - 1, 2);
    cout << "Pivot Type 2 (Random Element) Comparisons: " << comparisonCount << endl;
    comparisonCount = 0;
    quickSort(arr3, 0, size - 1, 3);
    cout << "Pivot Type 3 (Middle Element) Comparisons: " << comparisonCount << endl;
    comparisonCount = 0;
    quickSort(arr4, 0, size - 1, 4);
    cout << "Pivot Type 4 (Median of Three) Comparisons: " << comparisonCount << endl;
    return 0;
}
