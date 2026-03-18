Problem: Given an array of n-1 distinct integers in range [1, n], find the missing number.
Example: arr = [1, 2, 4, 5], n=5 → missing = 3

Approach 1: Sorting
Sort the array, then check where the sequence breaks.
cpp#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumberSort(vector<int> arr, int n) {
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n; // if all 1..n-1 are present, n is missing
}

int main() {
    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    cout << "Missing: " << missingNumberSort(arr, n) << endl; // 3
}
How it works: After sorting, element at index i should be i+1. First mismatch gives the answer.

Time: O(n log n)
Space: O(1)


Approach 2: Sum Formula (Gauss)
Sum of first n natural numbers = n*(n+1)/2. Subtract actual array sum from it.
cpp#include <iostream>
#include <vector>
using namespace std;

int missingNumberSum(const vector<int>& arr, int n) {
    long long expectedSum = (long long)n * (n + 1) / 2;
    long long actualSum = 0;
    for (int x : arr) actualSum += x;
    return expectedSum - actualSum;
}

int main() {
    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    cout << "Missing: " << missingNumberSum(arr, n) << endl; // 3
}
```

**How it works:**
```
expectedSum = 5*6/2 = 15
actualSum   = 1+2+4+5 = 12
missing     = 15 - 12 = 3

⚠️ Overflow risk: For very large n, n*(n+1) can overflow int. Always use long long.


Time: O(n)
Space: O(1)


Approach 3: XOR
XOR of a number with itself = 0. XOR everything from 1..n with everything in the array — paired numbers cancel out, leaving the missing one.
cpp#include <iostream>
#include <vector>
using namespace std;

int missingNumberXOR(const vector<int>& arr, int n) {
    int xorFull = 0;
    int xorArr  = 0;

    for (int i = 1; i <= n; i++) xorFull ^= i;
    for (int x : arr)             xorArr  ^= x;

    return xorFull ^ xorArr;
}

int main() {
    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    cout << "Missing: " << missingNumberXOR(arr, n) << endl; // 3
}
```

**How it works (tracing):**
```
xorFull = 1^2^3^4^5
xorArr  = 1^2^4^5

xorFull ^ xorArr = (1^1)^(2^2)^3^(4^4)^(5^5) = 0^0^3^0^0 = 3
No overflow possible. This is the most elegant approach.

Time: O(n)
Space: O(1)


Approach 4: Visited / Marking (In-place)
Use the array itself as a hash map. Mark index arr[i]-1 as negative to "visit" it. Unvisited index = missing number.
cpp#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int missingNumberMark(vector<int> arr, int n) {
    // Extend array to size n (missing element slot = 0)
    arr.push_back(0);

    for (int i = 0; i < n; i++) {
        int idx = abs(arr[i]) - 1;
        if (arr[idx] > 0) arr[idx] = -arr[idx];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) return i + 1;
    }
    return n;
}

int main() {
    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    cout << "Missing: " << missingNumberMark(arr, n) << endl; // 3
}
How it works:

For each value v, go to index v-1 and flip that element negative — marking it "seen"
Whichever index still has a positive value was never visited → index + 1 is missing


⚠️ Modifies the array (pass by value or restore after). Requires all values to be positive initially.


Time: O(n)
Space: O(1) extra (modifies in-place)


Approach 5: HashMap / Frequency Array
Store presence in a boolean array, then find the gap.
cpp#include <iostream>
#include <vector>
using namespace std;

int missingNumberHash(const vector<int>& arr, int n) {
    vector<bool> present(n + 1, false);

    for (int x : arr) present[x] = true;

    for (int i = 1; i <= n; i++) {
        if (!present[i]) return i;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    cout << "Missing: " << missingNumberHash(arr, n) << endl; // 3
}

Time: O(n)
Space: O(n) — the tradeoff here


Approach 6: Binary Search (if array is sorted)
If the array is already sorted, binary search on the index-value relationship.
cpp#include <iostream>
#include <vector>
using namespace std;

int missingNumberBinarySearch(const vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // If arr[mid] == mid+1, no missing on left side
        if (arr[mid] == mid + 1)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo + 1;
}

int main() {
    vector<int> arr = {1, 2, 4, 5}; // must be sorted
    cout << "Missing: " << missingNumberBinarySearch(arr) << endl; // 3
}
How it works: In a complete array, arr[i] == i+1 always. Once a number is missing, every element after shifts right by 1, so arr[i] > i+1. Binary search finds the exact boundary.

Time: O(log n)
Space: O(1)
Constraint: Array must already be sorted


Comparison Table
ApproachTimeSpaceNotesSortingO(n log n)O(1)Simple but slowSum FormulaO(n)O(1)Overflow risk for large nXORO(n)O(1)✅ Best general purposeIn-place MarkingO(n)O(1)Mutates arrayHashMapO(n)O(n)Easiest to understandBinary SearchO(log n)O(1)✅ Best, but needs sorted input

Which to Use?

Interview default → XOR (no overflow, O(n), elegant)
Sorted array given → Binary Search (O(log n) is hard to beat)
Quick and readable → Sum Formula (just use long long)
Never default to Sorting unless the problem forces it
 Sonnet 4.6Claude is AI and can make mistakes. Please double-check responses.