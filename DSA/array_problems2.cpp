#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

void rotateArray(int arr[],int n){
    int temp = arr[0];
    for (int i = 1; i < n;i++){
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    printArray(arr, n);
}

int main() {
    int n;
    cout << "enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "enter the elements of the array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    rotateArray(arr, n);
    return 0;
}