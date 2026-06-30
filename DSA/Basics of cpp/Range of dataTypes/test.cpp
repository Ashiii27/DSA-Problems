#include <iostream>
using namespace std;
#define ll long long 

int main(){
    ll n;
    cin >> n;

    if(n <= 0){
        return 0;
    }

    ll a = 0, b = 1;
    cout << a;
    
    for (ll i = 1; i < n; i++){
        cout << " " << b;
        ll c = a + b;
        a = b;
        b = c;
    }
    cout << endl;

    return 0;
}