#include<iostream>
using namespace std;

int main() {
    int m,n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    int a[10][10]; // Assuming a maximum size of 10x10
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cout << "--------------------------------------------" << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}