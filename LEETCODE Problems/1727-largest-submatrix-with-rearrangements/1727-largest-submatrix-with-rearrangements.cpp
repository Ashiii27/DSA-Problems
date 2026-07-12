class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        // Build heights
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];
            }
        }

        // Process each row
        for (int i = 0; i < m; i++) {
            vector<int> heights = matrix[i];

            sort(heights.begin(), heights.end(), greater<int>());

            for (int j = 0; j < n; j++) {
                ans = max(ans, heights[j] * (j + 1));
            }
        }

        return ans;
    }
};