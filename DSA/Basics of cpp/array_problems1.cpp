#include<bits/stdc++.h>
using namespace std;    

//solution for first problem
int maxElement(int arr[],int n) {
    //brute force
    //sort the array and then return the last element 

    //optimal approach
    int largest = arr[0];
    for (int i = 1; i < n;i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}

// solution for 2nd problem
int secondLargest(int arr[], int n) {
    int largest = arr[0];
    int secondLargest = INT_MIN;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

//Solution for problem 3
bool isSorted(int arr[],int n){
    for (int i = 1;i<n;i++){
        if (arr[i] < arr[i-1]){
            return false;
        }
    }
    return true;
}

//solution for problem 4
int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;

    int slow = 0;

    for (int fast = 1; fast < n; fast++) {
        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }

    return slow + 1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}


int main() {
    

int n;
cout<<"enter the size of the array : ";
cin>>n;
int arr[n];
cout<<"enter the array elements: ";
for(int i=0; i<n; i++){
    cin>>arr[i];
}

//Q1. Finding the largest element in an array
// int largest = maxElement(arr, n);
// cout<<"the largest element in the array is: "<<largest<<endl;

//Q.2 Second largest element in the array
// int secondLargestElement = secondLargest(arr, n);
// cout<<"the second largest element in the array is: "<<secondLargestElement<<endl;

//Q.3 check if array is sorted or not
// bool sorted = isSorted(arr, n);
// cout<<"the array is sorted: "<<sorted<<endl;

//Q.4 remove duplicates from sorted array
int newSize = removeDuplicates(arr, n);
cout<<"the array after removing duplicates is: ";
printArray(arr, newSize);


return 0;

}