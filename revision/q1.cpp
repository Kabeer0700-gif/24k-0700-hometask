#include <iostream>
using namespace std;

/*
    WHY SHELL SORT IS MORE EFFICIENT THAN INSERTION SORT:
    -----------------------------------------------------
    - Insertion Sort compares and shifts only *adjacent* elements.
      → So, if the smallest number is at the end, it takes many swaps to reach the front.
    
    - Shell Sort improves this by introducing a "gap".
      → It starts comparing elements that are far apart (gap = n/2, then gap /= 2).
      → This quickly moves smaller elements closer to the front.
      → Finally, a small gap (like 1) finishes sorting efficiently.

    For small arrays like [205, 102, 310, 450, 120, 90],
    Shell Sort reduces total swaps and comparisons, making it faster.
*/

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void shellSort(int arr[], int n) {
    
    for (int gap = n / 2; gap > 0; gap /= 2) {
        
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

          
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }

    
        cout << "After gap = " << gap << " → ";
        printArray(arr, n);
    }
}

int main() {
    int bookIDs[] = {205, 102, 310, 450, 120, 90};
    int n = sizeof(bookIDs) / sizeof(bookIDs[0]);

    cout << "Original Book IDs: ";
    printArray(bookIDs, n);

    shellSort(bookIDs, n);

    cout << "\nFinal Sorted Book IDs: ";
    printArray(bookIDs, n);

    return 0;
}
