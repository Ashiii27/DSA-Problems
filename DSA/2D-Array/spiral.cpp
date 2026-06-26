#include <iostream>
#include <vector>
using namespace std;

// ─── Clockwise Spiral ───────────────────────────────────────────
void printSpiralCW(const vector<vector<int>>& mat) {
    int top = 0, bottom = mat.size() - 1;
    int left = 0, right = mat[0].size() - 1;

    cout << "Clockwise: ";
    while (top <= bottom && left <= right) {
        // → Left to Right (top row)
        for (int i = left; i <= right; i++)
            cout << mat[top][i] << " ";
        top++;

        // ↓ Top to Bottom (right col)
        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;

        // ← Right to Left (bottom row)
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";
            bottom--;
        }

        // ↑ Bottom to Top (left col)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            left++;
        }
    }
    cout << endl;
}

// ─── Anti-Clockwise Spiral ──────────────────────────────────────
void printSpiralACW(const vector<vector<int>>& mat) {
    int top = 0, bottom = mat.size() - 1;
    int left = 0, right = mat[0].size() - 1;

    cout << "Anti-Clockwise: ";
    while (top <= bottom && left <= right) {
        // ↓ Top to Bottom (left col)
        for (int i = top; i <= bottom; i++)
            cout << mat[i][left] << " ";
        left++;

        // → Left to Right (bottom row)
        for (int i = left; i <= right; i++)
            cout << mat[bottom][i] << " ";
        bottom--;

        // ↑ Bottom to Top (right col)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][right] << " ";
            right--;
        }

        // ← Right to Left (top row)
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                cout << mat[top][i] << " ";
            top++;
        }
    }
    cout << endl;
}

// ─── Main ───────────────────────────────────────────────────────
int main() {
    // Test 1: Square 4×4
    vector<vector<int>> sq = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "=== 4x4 Square ===" << endl;
    printSpiralCW(sq);
    printSpiralACW(sq);

    // Test 2: Rectangular 3×5
    vector<vector<int>> rect = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15}
    };

    cout << "\n=== 3x5 Rectangle ===" << endl;
    printSpiralCW(rect);
    printSpiralACW(rect);

    // Test 3: Single row & single column edge cases
    vector<vector<int>> row = {{1, 2, 3, 4, 5}};
    vector<vector<int>> col = {{1}, {2}, {3}, {4}};

    cout << "\n=== 1x5 Row ===" << endl;
    printSpiralCW(row);

    cout << "\n=== 4x1 Column ===" << endl;
    printSpiralCW(col);

    return 0;
}


/* Output:
=== 4x4 Square ===
Clockwise:      1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Anti-Clockwise: 1 5 9 13 14 15 16 12 8 4 3 2 6 10 11 7

=== 3x5 Rectangle ===
Clockwise:      1 2 3 4 5 10 15 14 13 12 11 6 7 8 9
Anti-Clockwise: 1 6 11 12 13 14 15 10 5 4 3 2 7 8 9

=== 1x5 Row ===
Clockwise:      1 2 3 4 5

=== 4x1 Column ===
Clockwise:      1 2 3 4

How it works — the boundary shrinking trick:
Both directions use 4 pointers (top, bottom, left, right) that close in after each layer is printed.
DirectionLayer orderClockwise→ right, ↓ down, ← left, ↑ upAnti-CW↓ down, → right, ↑ up, ← left
The if (top <= bottom) and if (left <= right) guards before the 3rd and 4th passes handle the edge cases where a single row or column remains mid-traversal — without them you'd get duplicate elements.
Time: O(M×N) — every element visited once.

Space: O(1) extra — no auxiliary matrix needed. */