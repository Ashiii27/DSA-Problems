// ============================================================
//  PROBLEM: Find the element that appears ONCE
//           while every other element appears TWICE
//
//  Example: arr = {4, 1, 2, 1, 2}  →  Answer: 4
//           arr = {2, 2, 3, 7, 7}  →  Answer: 3
// ============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

// helper to print results cleanly
void printResult(const string& approach, int result) {
    cout << "[" << approach << "] Single element: " << result << endl;
}


// ============================================================
// APPROACH 1: BRUTE FORCE — count frequency manually
//
// For each element, count how many times it appears.
// If count == 1, that's our answer.
//
// Time  : O(n^2)
// Space : O(1)
//
// Notes : Simple to understand but very slow. Never use in
//         interviews unless asked for brute force first.
//         Two nested loops make it O(n^2).
// ============================================================

int bruteForce(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) count++;
        }
        if (count == 1) return arr[i];
    }
    return -1;
}


// ============================================================
// APPROACH 2: SORTING
//
// Sort the array. Now duplicates are adjacent.
// Walk through in steps of 2 — if arr[i] != arr[i+1],
// then arr[i] is the odd one out.
//
// Time  : O(n log n)  — dominated by sort
// Space : O(1)        — sort is in-place (or O(log n) stack for introsort)
//
// Notes : Better than brute force. Easy to visualize:
//         [1,1, 2,2, 3, 4,4]
//                    ^-- pair breaks here, arr[4]=3 is the answer
//         After sort, check pairs at indices (0,1), (2,3), (4,5)...
//         First broken pair gives the answer.
//         Edge case: if all pairs are fine, the last element is the answer.
// ============================================================

int sortingApproach(vector<int> arr) {           // pass by value to avoid mutating original
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n - 1; i += 2) {
        if (arr[i] != arr[i + 1]) return arr[i]; // pair broken → current element is single
    }
    return arr[n - 1];                           // last element has no pair
}


// ============================================================
// APPROACH 3: HASHMAP (unordered_map)
//
// Count frequency of each element using a hash map.
// Return the element whose frequency is 1.
//
// Time  : O(n)  average  (O(n^2) worst case due to hash collisions)
// Space : O(n)  — storing up to n/2 + 1 entries in the map
//
// Notes : Very readable and beginner-friendly. Good when you
//         can afford extra space. Two passes over data:
//           Pass 1 → build frequency map
//           Pass 2 → find the key with value 1
//         Can also be done in one pass if you erase on second
//         occurrence (shown in comment below).
// ============================================================

int hashmapApproach(const vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;
    for (auto& [key, val] : freq) {
        if (val == 1) return key;
    }
    return -1;

    // ---- ONE-PASS variant ----
    // for (int x : arr) {
    //     if (freq.count(x)) freq.erase(x);  // second occurrence: remove
    //     else freq[x] = 1;                  // first occurrence: add
    // }
    // return freq.begin()->first;            // only one entry left
}


// ============================================================
// APPROACH 4: XOR  ← THE BEST GENERAL APPROACH
//
// XOR properties that make this work:
//   a ^ a = 0       (same number XORed = 0)
//   a ^ 0 = a       (XOR with 0 = same number)
//   XOR is commutative and associative
//
// So: x1^x1 ^ x2^x2 ^ ... ^ single = 0^0^...^ single = single
//
// Time  : O(n)
// Space : O(1)
//
// Notes : THE go-to answer in interviews. No overflow risk,
//         no extra space, single pass.
//         Trace: arr = {4, 1, 2, 1, 2}
//           result = 0
//           ^ 4  →  4
//           ^ 1  →  5   (4^1 = 101^001 = 100... wait, 4=100, 1=001 → 101 = 5)
//           ^ 2  →  7   (5^2 = 101^010 = 111 = 7)
//           ^ 1  →  6   (7^1 = 111^001 = 110 = 6)
//           ^ 2  →  4   (6^2 = 110^010 = 100 = 4)  ← answer!
//         All duplicates cancel out bit by bit.
// ============================================================

int xorApproach(const vector<int>& arr) {
    int result = 0;
    for (int x : arr) result ^= x;
    return result;
}


// ============================================================
// APPROACH 5: BINARY SEARCH (array must be SORTED)
//
// In a sorted array with one single element:
//   → Before the single element, pairs start at EVEN indices
//   → After  the single element, pairs start at ODD  indices
//
// Use this property to binary search for the boundary.
//
// Time  : O(log n)  ← best time complexity of all approaches
// Space : O(1)
//
// Notes : Brilliant approach for sorted input. The invariant:
//           arr[mid] == arr[mid^1]  →  we're before or at the pair
//                                      containing single, so single is RIGHT
//           arr[mid] != arr[mid^1]  →  single is at mid or LEFT
//
//         Why mid^1?  XOR with 1 flips the last bit:
//           even index → mid^1 = mid+1  (checks right neighbor)
//           odd  index → mid^1 = mid-1  (checks left  neighbor)
//         This is cleaner than writing two separate if-else branches.
//
//         Example (sorted): [1,1, 2, 3,3, 4,4]
//                            0 1  2  3 4  5 6
//         mid=3 (odd), mid^1=2, arr[3]=3 != arr[2]=2 → go left
//         mid=1 (odd), mid^1=0, arr[1]=1 == arr[0]=1 → go right
//         mid=2 (even), lo=hi=2 → return arr[2] = 2  ✓
// ============================================================

int binarySearchApproach(vector<int> arr) {    // sorts internally, pass by value
    sort(arr.begin(), arr.end());              // remove this line if already sorted
    int lo = 0, hi = arr.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (mid % 2 == 1) mid--;              // ensure mid is always even (start of a pair)
        if (arr[mid] == arr[mid + 1])
            lo = mid + 2;                     // pair is intact, single is to the right
        else
            hi = mid;                         // pair is broken, single is here or to the left
    }
    return arr[lo];
}


// ============================================================
// APPROACH 6: BIT MANIPULATION — counting bits across all numbers
//
// For every bit position (0 to 31):
//   Count how many numbers in arr have that bit set.
//   If count % 3 != 0... wait, that's for "appears thrice" variant.
//
//   For the "appears twice" variant:
//   If count % 2 != 0 → the single element has that bit set.
//
// Reconstruct the single element from these bit counts.
//
// Time  : O(32 * n) = O(n)
// Space : O(1)
//
// Notes : This is the generalized version of XOR. XOR itself
//         implicitly does mod-2 on each bit position — this
//         approach makes that explicit.
//         More useful when the problem changes to "appears k times"
//         (e.g., k=3): just change % 2 to % 3.
//         Important for understanding why XOR works under the hood.
// ============================================================

int bitCountApproach(const vector<int>& arr) {
    int result = 0;
    for (int bit = 0; bit < 32; bit++) {
        int bitSum = 0;
        for (int x : arr) {
            if (x & (1 << bit)) bitSum++;    // count numbers that have this bit set
        }
        if (bitSum % 2 != 0) {              // odd count → single element has this bit
            result |= (1 << bit);
        }
    }
    return result;
}


// ============================================================
// COMPARISON TABLE
//
// +-----------------+-----------+--------+----------------------+
// | Approach        |   Time    | Space  | Notes                |
// +-----------------+-----------+--------+----------------------+
// | Brute Force     | O(n^2)    | O(1)   | Never use            |
// | Sorting         | O(n logn) | O(1)   | Okay fallback        |
// | HashMap         | O(n)      | O(n)   | Readable, uses space |
// | XOR             | O(n)      | O(1)   | Best general purpose |
// | Binary Search   | O(log n)  | O(1)   | Best if sorted       |
// | Bit Count       | O(32n)    | O(1)   | Generalizes to k>2   |
// +-----------------+-----------+--------+----------------------+
//
// INTERVIEW STRATEGY:
//   → Always lead with XOR (optimal, elegant, no edge cases)
//   → Mention Binary Search if interviewer asks for better on sorted input
//   → Mention Bit Count if they ask "what if duplicates appear 3 times?"
//   → HashMap if they want readable/maintainable over optimal
// ============================================================


// ============================================================
// DRIVER
// ============================================================

int main() {
    vector<int> arr1 = {4, 1, 2, 1, 2};   // single = 4
    vector<int> arr2 = {2, 2, 3, 7, 7};   // single = 3
    vector<int> arr3 = {1};                // single = 1 (edge: only one element)
    vector<int> arr4 = {1, 1, 2, 2, 9};   // single = 9 (single at end)

    cout << "=== arr1 = {4,1,2,1,2} ===" << endl;
    printResult("Brute Force   ", bruteForce(arr1));
    printResult("Sorting       ", sortingApproach(arr1));
    printResult("HashMap       ", hashmapApproach(arr1));
    printResult("XOR           ", xorApproach(arr1));
    printResult("Binary Search ", binarySearchApproach(arr1));
    printResult("Bit Count     ", bitCountApproach(arr1));

    cout << "\n=== arr2 = {2,2,3,7,7} ===" << endl;
    printResult("XOR           ", xorApproach(arr2));
    printResult("Binary Search ", binarySearchApproach(arr2));

    cout << "\n=== arr3 = {1} ===" << endl;
    printResult("XOR           ", xorApproach(arr3));

    cout << "\n=== arr4 = {1,1,2,2,9} ===" << endl;
    printResult("XOR           ", xorApproach(arr4));
    printResult("Binary Search ", binarySearchApproach(arr4));

    return 0;
}