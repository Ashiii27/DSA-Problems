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

    string a,b;
    cin >> a;
    cin >> b;

    for(int i = 0; i < a.length(); i++) {
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
    }

    if( a == b){
        cout << 0;
    }else if(a<b){
        cout << -1;
    }else{
        cout << 1;
    }

        return 0;
}