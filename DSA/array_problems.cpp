//Find all pairs (i,j) such that i<j and arr[i]>arr[j]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {4,6,2,8,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }

    return 0;
}