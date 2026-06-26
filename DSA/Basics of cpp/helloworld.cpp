#include<iostream>
using namespace std;

int main() {
    int n = 10;
    char hello = 'h';
    float pie = 3.14;
    double big = 4.57297;
    bool num = true;
    cout << num<<endl;
    cout << big << endl;
    cout << pie <<endl;
    cout<< hello <<endl;;
    cout<< n << endl;
    cout<< "Hello world"<<endl;
    cout << "******************************************" << endl;
    cout << sizeof(num)<<endl; //size of 
    cout << sizeof(big) << endl;
    cout <<sizeof(pie) <<endl;
    cout<< sizeof(hello) <<endl;;
    cout<< sizeof(n) << endl;
    cout<< sizeof("Hello world");
}