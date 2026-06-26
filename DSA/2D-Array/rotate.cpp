//Rotate a 2D matrix by 90 degrees clockwise

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ─────────────────────────────────────────────
// APPROACH 1: IN-PLACE  |  O(N²) time, O(1) space
// Works ONLY for N×N (square) matrices
//
// Steps:
//   1. Transpose  → swap matrix[i][j] with matrix[j][i]
//   2. Reverse each row
//
// Why this works:
//   Clockwise 90° maps (i, j) → (j, N-1-i)
//   Transpose maps    (i, j) → (j, i)
//   Row-reverse maps  (j, i) → (j, N-1-i)   ✓
// ─────────────────────────────────────────────

void rotateInPlace(vector<vector<int>>& mat) {
    int n = mat.size();

    // Step 1: Transpose (only upper triangle to avoid double-swap)
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());
}

// ─────────────────────────────────────────────
// APPROACH 2: NEW MATRIX  |  O(N²) time, O(N²) space
// Cleaner to reason about, uses extra N×N matrix
//
// Clockwise 90° formula:
//   new[j][N-1-i] = old[i][j]
//   → column j in old  becomes row j in new
//   → row i in old     becomes column (N-1-i) in new
// ─────────────────────────────────────────────
vector<vector<int>> rotateNewMatrix(const vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[j][n - 1 - i] = mat[i][j];

    return result;
}

// ─────────────────────────────────────────────
// Utility: Print matrix
// ─────────────────────────────────────────────
void printMatrix(const vector<vector<int>>& mat, const string& label) {
    cout << label << ":\n";
    for (const auto& row : mat) {
        for (int val : row)
            cout << val << "\t";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    // ── Test with 3×3 ──
    vector<vector<int>> mat3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printMatrix(mat3, "Original 3×3");

    // New matrix approach (non-destructive, so test first)
    auto rotated3 = rotateNewMatrix(mat3);
    printMatrix(rotated3, "After 90° CW — New Matrix");

    // In-place approach
    rotateInPlace(mat3);
    printMatrix(mat3, "After 90° CW — In-Place");

    // ── Test with 4×4 ──
    vector<vector<int>> mat4 = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printMatrix(mat4, "Original 4×4");

    rotateInPlace(mat4);
    printMatrix(mat4, "After 90° CW — In-Place");

    return 0;
}