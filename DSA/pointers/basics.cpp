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

    int a = 10;
    int *p = &a;
    int **ptr = &p;

    cout << p << endl
         << *p << endl
         << ptr << endl
         << *ptr << endl
         << *(*ptr) << endl;

    return 0;
}