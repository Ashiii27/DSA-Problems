#include<bits/stdc++.h>
using namespace std;

int main() {
    // string s;
    // cout << "enter the string:";
    // cin >> s;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }

        // pre-compute
        //  int hash[256] = {0};
        //  for (int i = 0; i < s.size(); i++)
        //      hash[s[i]]++;

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    //iterate in the map
    for(auto it:mpp) {
        cout << it.first << "->" << it.second << endl;
    }
    

    int q;
    cout << "enter the number of times :";
    cin >> q;
    while(q--){
        int c;
        cin >> c;
        //fetch
        cout << mpp[c] << endl;
    }
    return 0;
}