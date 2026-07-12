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

    string s;
    cin >> s;

    for(auto i:s){
        i = tolower(i);
        if(!(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'y')){
            cout << "." << i;
        }
    }
    cout << endl;
}