#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

void factorise(int n){
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
                cout << i << " ";
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n != 1) {
            cout << n << " ";
        }
    }

int main() {

    factorise(1000);

    return 0;
}