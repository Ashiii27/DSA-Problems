#include<iostream>
using namespace std;

void reverse(int arr[5])
    {
        cout << "original array : ";
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";
        cout << endl;
        cout << "reverse of the array : ";
        for (int i = 4; i >= 0;i--)
            cout << arr[i] << " ";

        return;
    }



void maximum(int arr[5]){
    int max = arr[0];
    for (int i = 1; i < 5;i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    cout << max;
    return;
}

void minimum(int arr[5]){
    int min = arr[0];
    for (int i = 1; i <= 4;i++)
    {
        if(arr[i]<min)
            min = arr[i];
    }
    cout << min;
    return;
}

void odd(int arr[5]){
    for (int i = 0; i < 5;i++)
    {
        if(arr[i]%2==1)
            cout << arr[i] << " ";
    }
    return;
}

void even(int arr[5]){
    for (int i = 0; i < 5;i++)
    {
        if(arr[i]%2==0)
            cout << arr[i] << " ";
    }
    return;
}

int main(){

    int arr[5] = { 1, 2, 3, 4, 5 };
   // reverse(arr);
    //maximum(arr);
    //minimum(arr);
    //odd(arr);
    even(arr);
    return 0;
}