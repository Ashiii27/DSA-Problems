![alt text](image.png)

```cpp

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

    int tc;
    cin >> tc;

    while(tc--) {
        string s;
        cin >> s;

        int n = s.length();

        if(n > 10){
            cout << s[0] << n - 2 << s[n - 1] << endl;
        } else{
            cout << s << endl;
        }

    }

        return 0;
}

```

