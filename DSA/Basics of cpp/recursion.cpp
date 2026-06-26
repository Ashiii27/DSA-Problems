#include <iostream>
using namespace std;

int count = 0;
void printNum() {
    if(count==4)
        return;
    cout << count << endl;
    count++;
    printNum();
}

void printName(string s,int n) {
    if(count>=n)
        return;
    cout << s << endl;
    count++;
    printName(s,n);
}

void  printNum(int n) {
    if(count>n)
        return;
    cout << count <<" ";
    count++;
    printNum(n);
    return;
}

void backTrack(int i,int n){
    if (i>n)
        return;
    backTrack(i + 1, n);
    cout << i << " ";
    return;
}

void suM(int i,int sum) {
    if (i<1)
    {
        cout << sum;
        return;
    }
    suM(i - 1, sum + i);
    return;
}

int suMM(int i) {
    if (i==0)
    {
        return 0;
    }
    return i + suMM(i - 1);
}

int factorial1(int i){
    if(i==1)
        return 1;
    return i * factorial1(i - 1);
}

void factorial2(int i,int fact){
    if(i<1) {
        cout << fact;
        return;
    }
    factorial2(i - 1, fact * i);
    return;
}

void rev(int i,int arr[],int n){
    if(i>=n/2)
        return;
    swap(arr[i], arr[n - i - 1]);
    rev(i+1, arr, n);
}

bool pali(int i ,string &a) {
    if(i>=a.size()/2)
        return true;
    if(a[i]!=a[a.size()-i-1])
        return false;
    return pali(i + 1, a);
}

int fib(int n){
    if (n<=1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int main() {
    // printNum();
    
    // string s;
    // cout << "Enter the name : " ;
    // cin >> s;
    // int n,i;
    // i = 1;
    // int i, sum,fact;
    // sum = 0;
    // fact = 1;
    // cout << "Enter the number : ";
    // cin >> i;
    // factorial2(i, fact);
    // int fact = factorial1(i);
    // cout << fact;
    // suM(i, 0);
    // int ans = suMM(i);
    // cout << ans;
    //printName(s,n);
    //printNum(n);
    // backTrack(i, n);
    // int n;
    // cout << "enter n:";
    // cin >> n;
    // int arr[n];
    // cout << "enter the array :";
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    // rev(0, arr, n);
    // for (int i = 0; i < n;i++)
    //     cout << arr[i]<<" ";

    // string a;
    // cout << "enter the word : ";
    // cin >> a;
    // cout << pali(0,a);

    int n;
    cout << "enter the num : ";
    cin >> n;
    cout << fib(n);
    return 0;
}