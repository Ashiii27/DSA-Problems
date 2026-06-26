#include<iostream>
using namespace std;
int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    // for (int i = 0; i < 5;i++)
    // {
    //     for (int j = 0; j < 5 - i;j++)
    //         cout << arr[j]<<" ";
    //     cout << endl;
    // }

    // output

    // 1 2 3 4 5 
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1

//----------------------------------------------------------------

    // for (int i = 0; i < 5;i++)
    // {
    //     for (int j = i; j < 5;j++)
    //         cout << arr[j] << " ";
    //     cout << endl;
    // }

//--------------------------------------------------------------

    for (int i = 0; i < 5;i++)
    {
        for (int j = 4-i; j >= 0;j--)
        {

            cout << arr[j] << " ";
        }
        cout << endl;
    }
        return 0;
} 