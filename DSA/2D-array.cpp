#include<iostream>
#include<vector>

using namespace std;

int main() {
    // int m,n;
    // cout << "Enter the number of rows and columns: ";
    // cin >> m >> n;
    // int a[10][10]; // Assuming a maximum size of 10x10
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 0; j < n; j++){
    //         cin >> a[i][j];
    //     }
    // }
    // cout << "--------------------------------------------" << endl;
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 0; j < n; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

//How to make 2D dyanmic vector

    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    vector<vector<int>> x(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x[i][j];
        }
    }
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}