class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                // switch baesd on diagonal, i + j + 1 == n
                if (i + j + 1 == n)
                    continue;
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][n - 1 - i];
                matrix[n - 1 - j][n - 1 - i] = temp;
            }
        }
        // rotate by middle row
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = temp;
            }    
        }
        return;
    }
};