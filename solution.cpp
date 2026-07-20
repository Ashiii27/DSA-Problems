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

    int t;
    cin >> t;

    while(t--) {
        int x;
        cin >> x;
        if(x<0){
            cout<<x<<"\n";
        }
        else{
            cout << x + 1 << "\n";
        }
            
    }

    return 0;
}