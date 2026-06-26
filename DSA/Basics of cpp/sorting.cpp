#include<iostream>
using namespace std;

void selectionSort(int n, int arr[]) {
    for (int i = 0; i < n - 1; i++) {
        int mini = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini])
                mini = j;
        }

        swap(arr[i], arr[mini]);
    }
}

void bubble_sort(int n, int arr[]) {
    for (int i = 0; i < n - 1; i++) {
        int didSwap = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }
}

void insertion_sort(int n, int arr[]) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


int main() {
    int n;
    cout << "enter the size of array : ";
    cin >> n;

    int arr[n];

    cout << "enter the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //selectionSort(n, arr);
    //bubble_sort(n, arr);
    insertion_sort(n, arr);

    cout << "sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

//Time Complexity: O(n log n) 
// Space Complexity: O(n) for the temporary left/right vectors