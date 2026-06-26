#include<iostream>
using namespace std;

int isEvenOdd(int num){
    if(num%2==0)
        return 0;
        else
            return 1;
}

int factorial(int num){
    int fact = 1;
    for (int i = 1; i <= num;i++)
         fact = fact * i;

    return fact;
}
int main(){
    int num;
    cin >> num;
    // int n = isEvenOdd(num);
    // if(n==0)
    //     cout << "even";
    // else
    //     cout << "odd";
    int result = factorial(num);
    cout << result;
    return 0;
}