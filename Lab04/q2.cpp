#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n, int &comp) {
    comp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void insertionSort(int arr[], int n, int &comp) {
    comp = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comp++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else break;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comp) {
    comp = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        int t = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = t;
    }
}

void shellSort(int arr[], int n, int &comp) {
    comp = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap) {
                comp++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                } else break;
            }
            arr[j] = temp;
        }
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    int n1 = 20, n2 = 100;
    int arr1[20], arr2[100];
    for (int i = 0; i < n1; i++) arr1[i] = rand() % 100 + 1;
    for (int i = 0; i < n2; i++) arr2[i] = rand() % 100 + 1;

    int temp[100], comp;

    cout << "Array with 20 elements:" << endl;
    copyArray(arr1, temp, n1);
    bubbleSort(temp, n1, comp);
    cout << "Bubble Sort: "; display(temp, n1);
    cout << "Comparisons: " << comp << endl;

    copyArray(arr1, temp, n1);
    insertionSort(temp, n1, comp);
    cout << "Insertion Sort: "; display(temp, n1);
    cout << "Comparisons: " << comp << endl;

    copyArray(arr1, temp, n1);
    selectionSort(temp, n1, comp);
    cout << "Selection Sort: "; display(temp, n1);
    cout << "Comparisons: " << comp << endl;

    copyArray(arr1, temp, n1);
    shellSort(temp, n1, comp);
    cout << "Shell Sort: "; display(temp, n1);
    cout << "Comparisons: " << comp << endl;

    cout << "\nArray with 100 elements:" << endl;
    copyArray(arr2, temp, n2);
    bubbleSort(temp, n2, comp);
    cout << "Bubble Sort Comparisons: " << comp << endl;

    copyArray(arr2, temp, n2);
    insertionSort(temp, n2, comp);
    cout << "Insertion Sort Comparisons: " << comp << endl;

    copyArray(arr2, temp, n2);
    selectionSort(temp, n2, comp);
    cout << "Selection Sort Comparisons: " << comp << endl;

    copyArray(arr2, temp, n2);
    shellSort(temp, n2, comp);
    cout << "Shell Sort Comparisons: " << comp << endl;

    return 0;
}
