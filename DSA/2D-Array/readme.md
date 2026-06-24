# 2D Arrays in C++ — Complete Guide

> Prerequisite: Comfortable with 1D arrays. This guide builds directly on that.

---

## 1. What Is a 2D Array?

Think of a 1D array as a single row of boxes:

```
arr[5] → [ 10 | 20 | 30 | 40 | 50 ]
            0    1    2    3    4
```

A 2D array is multiple rows stacked — a **grid/matrix**:

```
arr[3][4] →
         col0  col1  col2  col3
row 0  [ 1  |  2  |  3  |  4  ]
row 1  [ 5  |  6  |  7  |  8  ]
row 2  [ 9  | 10  | 11  | 12  ]
```

Each element is accessed as `arr[row][col]`.

**Memory reality:** C++ stores 2D arrays in **row-major order** — all of row 0 first, then row 1, then row 2, contiguously in memory. This matters for cache performance (always traverse row by row).

---

## 2. Declaration & Initialization

### 2.1 Static Declaration (size known at compile time)

```cpp
int arr[3][4];               // uninitialized — garbage values inside
int arr[3][4] = {0};         // all elements set to 0
```

### 2.2 Declaration with Initializer List

```cpp
int arr[3][4] = {
    {1,  2,  3,  4},   // row 0
    {5,  6,  7,  8},   // row 1
    {9, 10, 11, 12}    // row 2
};
```

You can also write it flat — C++ fills row by row:

```cpp
int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
```

Partial initialization — remaining elements become 0:

```cpp
int arr[3][4] = {{1, 2}};   // only arr[0][0]=1, arr[0][1]=2; rest are 0
```

### 2.3 Dynamic Allocation (size known at runtime)

```cpp
int rows = 3, cols = 4;

// Method 1: vector of vectors (most common in competitive/placement)
vector<vector<int>> arr(rows, vector<int>(cols, 0));

// Method 2: new (manual memory management — avoid unless needed)
int** arr = new int*[rows];
for (int i = 0; i < rows; i++)
    arr[i] = new int[cols];
// ... use arr ...
// Don't forget to free:
for (int i = 0; i < rows; i++) delete[] arr[i];
delete[] arr;
```

> **Placement Advice:** Use `vector<vector<int>>` in LeetCode/interviews. Static arrays for competitive programming where speed matters.

---

## 3. Taking Input

### 3.1 Static 2D Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;           // rows, cols

    int arr[n][m];           // VLA — works in GCC, not standard C++

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    return 0;
}
```

### 3.2 Vector of Vectors (Recommended)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    return 0;
}
```

### 3.3 Square Matrix (n × n)

```cpp
int n;
cin >> n;
vector<vector<int>> mat(n, vector<int>(n));

for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        cin >> mat[i][j];
```

---

## 4. Printing — All Ways

### 4.1 Standard Nested Loop (Most Common)

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
        cout << arr[i][j] << " ";
    cout << "\n";
}
```

Output:
```
1 2 3 4
5 6 7 8
9 10 11 12
```

### 4.2 Range-Based For Loop (Clean Syntax)

```cpp
for (auto& row : arr)
    for (auto& val : row)
        cout << val << " ";
// prints all in one line — add "\n" after inner loop for matrix format
```

```cpp
for (auto& row : arr) {
    for (auto& val : row)
        cout << val << "\t";
    cout << "\n";
}
```

### 4.3 Pretty Matrix Print with Borders

```cpp
for (int i = 0; i < n; i++) {
    cout << "[ ";
    for (int j = 0; j < m; j++) {
        cout << arr[i][j];
        if (j < m - 1) cout << ", ";
    }
    cout << " ]\n";
}
```

Output:
```
[ 1, 2, 3, 4 ]
[ 5, 6, 7, 8 ]
[ 9, 10, 11, 12 ]
```

### 4.4 Print as 1D (Flattened)

```cpp
// Works only for static arrays
int* flat = &arr[0][0];
for (int i = 0; i < n * m; i++)
    cout << flat[i] << " ";
```

### 4.5 Print Specific Patterns

```cpp
// Print only upper triangle
for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
        cout << mat[i][j] << " ";

// Print only diagonal
for (int i = 0; i < n; i++)
    cout << mat[i][i] << " ";

// Print anti-diagonal
for (int i = 0; i < n; i++)
    cout << mat[i][n - 1 - i] << " ";
```

---

## 5. Common Traversal Patterns

These patterns come up repeatedly in placement problems.

### 5.1 Row-wise Traversal

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        // process mat[i][j]
```

### 5.2 Column-wise Traversal

```cpp
for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++)
        // process mat[i][j]
```

> Note: Row-wise is faster due to cache locality. Column-wise causes cache misses.

### 5.3 Diagonal Traversal

```cpp
// Main diagonal (top-left to bottom-right)
for (int i = 0; i < n; i++)
    cout << mat[i][i];

// Anti-diagonal (top-right to bottom-left)
for (int i = 0; i < n; i++)
    cout << mat[i][n - 1 - i];
```

### 5.4 Spiral Traversal (Important for Interviews)

```cpp
void spiralPrint(vector<vector<int>>& mat, int n, int m) {
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Left → Right
        for (int j = left; j <= right; j++) cout << mat[top][j] << " ";
        top++;

        // Top → Bottom
        for (int i = top; i <= bottom; i++) cout << mat[i][right] << " ";
        right--;

        // Right → Left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) cout << mat[bottom][j] << " ";
            bottom--;
        }

        // Bottom → Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) cout << mat[i][left] << " ";
            left++;
        }
    }
}
```

---

## 6. Passing 2D Arrays to Functions

This is where most beginners get confused.

### 6.1 Static Array — Must Specify Column Size

```cpp
// Column size MUST be specified — row size is optional
void print(int arr[][4], int rows) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
}

int main() {
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    print(arr, 3);
}
```

### 6.2 Vector of Vectors — Cleanest

```cpp
void print(vector<vector<int>>& mat) {
    for (auto& row : mat)
        for (auto& val : row)
            cout << val << " ";
}
```

### 6.3 Pointer-based (Advanced)

```cpp
void print(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cout << *(arr + i * cols + j) << " ";
}

// Call: print(&arr[0][0], 3, 4);
```

---

## 7. Key Operations

### 7.1 Transpose

Swap `mat[i][j]` with `mat[j][i]`.

```cpp
// In-place (only for square matrices)
void transpose(vector<vector<int>>& mat, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
}
```

```cpp
// For non-square (n x m) → result is m x n
vector<vector<int>> transpose(vector<vector<int>>& mat, int n, int m) {
    vector<vector<int>> result(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            result[j][i] = mat[i][j];
    return result;
}
```

### 7.2 Rotate 90° Clockwise

```
Step 1: Transpose
Step 2: Reverse each row
```

```cpp
void rotate90(vector<vector<int>>& mat, int n) {
    // Transpose
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);

    // Reverse each row
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());
}
```

### 7.3 Rotate 90° Anti-Clockwise

```
Step 1: Transpose
Step 2: Reverse each column (or reverse row order)
```

```cpp
void rotate90CCW(vector<vector<int>>& mat, int n) {
    // Transpose
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);

    // Reverse each column
    for (int j = 0; j < n; j++)
        for (int i = 0, k = n - 1; i < k; i++, k--)
            swap(mat[i][j], mat[k][j]);
}
```

### 7.4 Search in Sorted Matrix (Staircase Search)

For a matrix sorted row-wise and column-wise:

```cpp
bool search(vector<vector<int>>& mat, int n, int m, int target) {
    int i = 0, j = m - 1;       // start: top-right corner
    while (i < n && j >= 0) {
        if (mat[i][j] == target) return true;
        else if (mat[i][j] > target) j--;   // go left
        else i++;                            // go down
    }
    return false;
}
// Time: O(n + m)
```

---

## 8. Practice Questions

### 🟢 Easy

**Q1. Row Sum and Column Sum**
Given an n×m matrix, print the sum of each row and each column.

```
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
Row sums: 6 15 24
Col sums: 12 15 18
```

**Q2. Find the Maximum in Each Row**
Print the maximum element of every row.

**Q3. Count Zeros in the Matrix**
Given a binary matrix (0s and 1s), count total zeros.

**Q4. Print the Boundary Elements**
Given an n×m matrix, print only the elements on the border (first row, last row, first col, last col).

---

### 🟡 Medium — Matrix Operations

**Q5. Transpose a Non-Square Matrix**
Input: n×m matrix → Output: m×n transposed matrix.

**Q6. Rotate Matrix 90° Clockwise (In-place)**
Classic interview question. Only for square matrices. Solve without extra space.

**LC Link:** [LeetCode 48 — Rotate Image](https://leetcode.com/problems/rotate-image/)

**Q7. Set Matrix Zeroes**
If any element is 0, set its entire row and column to 0. Do it in-place.

**LC Link:** [LeetCode 73 — Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)

**Q8. Diagonal Sum**
Find the sum of both diagonals. If n is odd, the center element should not be counted twice.

**LC Link:** [LeetCode 1572 — Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)

---

### 🟡 Medium — Searching & Traversal

**Q9. Spiral Order Matrix**
Return all elements of the matrix in spiral order.

**LC Link:** [LeetCode 54 — Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

**Q10. Search a 2D Matrix**
Integers in each row are sorted left to right. Last integer of each row is less than first of next. Search for a target in O(log(n*m)).

**LC Link:** [LeetCode 74 — Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

**Q11. Search a 2D Matrix II**
Each row and column is sorted independently. Find target in O(n + m).

**LC Link:** [LeetCode 240 — Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)

**Q12. Number of Islands**
Given a binary grid of '1's (land) and '0's (water), count the number of islands using BFS/DFS.

**LC Link:** [LeetCode 200 — Number of Islands](https://leetcode.com/problems/number-of-islands/)

---

### 🔴 Hard / Interview-Level

**Q13. Generate Spiral Matrix**
Given n, generate an n×n matrix filled with integers 1 to n² in spiral order.

**LC Link:** [LeetCode 59 — Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)

**Q14. Largest Rectangle in Histogram → apply to Matrix**
Find the largest rectangle containing only 1s in a binary matrix.

**LC Link:** [LeetCode 85 — Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

**Q15. Word Search in Grid**
Given a board of characters and a word, return true if the word exists in the grid (horizontally/vertically connected). Use DFS + backtracking.

**LC Link:** [LeetCode 79 — Word Search](https://leetcode.com/problems/word-search/)

---

## 9. Common Mistakes & Tips

| Mistake | Fix |
|---|---|
| Accessing `arr[i][j]` where `j >= cols` | Always bounds-check in nested loops |
| Column-wise traversal on large matrices | Prefer row-wise for cache efficiency |
| Forgetting to pass column size in static arrays to functions | Use `vector<vector<int>>` or pass cols explicitly |
| Off-by-one in spiral traversal | Add `if (top <= bottom)` checks for right→left and bottom→top |
| Modifying matrix while reading it (Q7 mistake) | Use first row/col as markers, or use a separate set |

---

## 10. Quick Reference Cheatsheet

```cpp
// Declaration
vector<vector<int>> mat(n, vector<int>(m, 0));

// Input
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cin >> mat[i][j];

// Output
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
        cout << mat[i][j] << " ";
    cout << "\n";
}

// Transpose (square)
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        swap(mat[i][j], mat[j][i]);

// Rotate 90° CW = Transpose + Reverse each row
// Rotate 90° CCW = Transpose + Reverse each column

// Staircase search (sorted matrix)
int i = 0, j = m - 1;
while (i < n && j >= 0) {
    if (mat[i][j] == target) { /* found */ }
    else if (mat[i][j] > target) j--;
    else i++;
}
```

---

*Happy grinding, Ash. Start with Q1–Q4, then tackle the LC mediums in order. Q9 (Spiral) and Q11 (Search Matrix II) are the highest-frequency ones in placements.*