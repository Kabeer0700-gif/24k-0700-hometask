#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int id;
    float salary;
};

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].salary >= R[j].salary) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Employee emp[12];

    for (int i = 0; i < 12; i++)
        cin >> emp[i].name >> emp[i].id >> emp[i].salary;

    mergeSort(emp, 0, 11);

    cout << "\nTop 3 Highest-Paid Employees:\n";
    for (int i = 0; i < 3; i++)
        cout << emp[i].name << " | " << emp[i].id << " | " << emp[i].salary << endl;
}
