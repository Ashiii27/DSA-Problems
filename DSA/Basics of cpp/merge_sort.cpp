#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& array, int leftIndex, int middleIndex, int rightIndex) {
    int leftSize = middleIndex - leftIndex + 1;
    int rightSize = rightIndex - middleIndex;

    vector<int> leftArray(leftSize);
    vector<int> rightArray(rightSize);

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = array[leftIndex + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = array[middleIndex + 1 + j];

    int leftPointer = 0, rightPointer = 0;
    int mergedPointer = leftIndex;

    while (leftPointer < leftSize && rightPointer < rightSize) {
        if (leftArray[leftPointer] <= rightArray[rightPointer]) {
            array[mergedPointer] = leftArray[leftPointer];
            leftPointer++;
        } else {
            array[mergedPointer] = rightArray[rightPointer];
            rightPointer++;
        }
        mergedPointer++;
    }

    while (leftPointer < leftSize) {
        array[mergedPointer] = leftArray[leftPointer];
        leftPointer++;
        mergedPointer++;
    }

    while (rightPointer < rightSize) {
        array[mergedPointer] = rightArray[rightPointer];
        rightPointer++;
        mergedPointer++;
    }
}

void mergeSort(vector<int>& array, int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        mergeSort(array, leftIndex, middleIndex);
        mergeSort(array, middleIndex + 1, rightIndex);
        merge(array, leftIndex, middleIndex, rightIndex);
    }
}

void printArray(const vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i];
        if (i < array.size() - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    vector<int> array(arraySize);
    cout << "Enter " << arraySize << " elements: ";
    for (int i = 0; i < arraySize; i++)
        cin >> array[i];

    cout << "Array before sorting: ";
    printArray(array);

    mergeSort(array, 0, arraySize - 1);

    cout << "Array after sorting:  ";
    printArray(array);

    return 0;
}