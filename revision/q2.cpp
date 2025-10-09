// Shell Sort is preferred at airports because it sorts faster than Bubble Sort,
// especially for medium-sized datasets, reducing passenger waiting time.

#include <iostream>
using namespace std;

/*
    REASONS WHY SHELL SORT IS BETTER THAN BUBBLE SORT:
    ---------------------------------------------------
    - Bubble Sort compares adjacent elements only (slow, O(n^2) time complexity).
    - Shell Sort compares elements far apart (using a gap), moving heavy items quickly
      toward the end and light ones toward the start.
    - This reduces total swaps and passes needed.

    REAL-LIFE REASON (AIRPORT):
    ----------------------------
    Airports need efficiency — thousands of bags must be processed quickly.
    Shell Sort minimizes comparisons and speeds up sorting before scanning.

    PERFORMANCE NOTE:
    -----------------
    - If luggage weights are *nearly sorted*, Shell Sort becomes extremely fast,
      approaching O(n log n), because fewer shifts are required.
    - Bubble Sort, even on nearly sorted data, still needs many passes to confirm order.
*/

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
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
    int luggage[] = {32, 25, 40, 12, 18, 50, 28};
    int n = sizeof(luggage) / sizeof(luggage[0]);

    cout << "Original Luggage Weights (kg): ";
    printArray(luggage, n);

    shellSort(luggage, n);

    cout << "\nFinal Sorted Luggage Weights (Lightest → Heaviest): ";
    printArray(luggage, n);

    cout << "\nEFFICIENCY COMPARISON:\n";
    cout << "- Bubble Sort: O(n^2) → very slow for large luggage lists.\n";
    cout << "- Shell Sort: Between O(n log n) and O(n^1.5) → much faster.\n";
    cout << "- If luggage is nearly sorted, Shell Sort becomes almost linear.\n";
    cout << "- Therefore, airports prefer Shell Sort for faster baggage processing.\n";

    return 0;
}
