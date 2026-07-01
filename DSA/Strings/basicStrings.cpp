#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int main() {
    
    /*char ch[5]= {'h','e','l','l','o'};
    //cout << ch << endl;
    //char ch1[5] = "hello"; // we can't do this as the null char can't get the slot allocated
    char ch2[6] = "hello"; // this is correct
    //cout << ch1 << endl;
    cout << ch2 << endl;
    return 0;  */

    //string - set of characters ,  you can change the characters
    //string literal - a set of characters , it is not editable

    string a = "hello";
    auto i = "abc";

    reverse(a.begin(),a.end());  //for reversing a string
    cout << a;
}