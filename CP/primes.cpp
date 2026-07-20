// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// using namespace std;

// // void prime(int n){
// //     if(n==0 || n==1){
// //         cout<<"not prime"<<endl;
// //     }

// //     else{
// //         for (int i = 2; i * i <= n;i++){
// //             if(n%i==0){
// //                 cout<<"not prime"<<endl;
// //                 return;
// //             }
// //         }
// //         cout<<"prime"<<endl;
// //     }
// // }

// void sieve(int n){
//     bool primes[n + 1];
//     fill(primes, primes + n + 1, true);
//     primes[0] = primes[1] = false;
//     for (int i = 2; i * i <= n; i++) {
//         cout << i << " " << endl;
//         if (primes[i]) {
//             for (int j = i * i; j <= n; j += i) {
//                 primes[j] = false;
//             }
//         }
//     }
// }

// int main() {

//     int n = 100;
//     //cin>>n;
//     //prime(n);
//     sieve(n);

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void sieve(int n) {     //TC for sieve is O(NlogLogN) or O(N) estimate
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (primes[i]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n = 100;
    sieve(n);
    return 0;
}