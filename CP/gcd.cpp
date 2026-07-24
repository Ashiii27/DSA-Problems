#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a = 12, b = 18;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;

    return 0;
}