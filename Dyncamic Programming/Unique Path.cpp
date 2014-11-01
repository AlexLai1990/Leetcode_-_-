/*
 DP
 m_path[i] += m_path[i - 1];
 m_path[0] = 1;
 */

// if using factorial way, the count might overflow
int uniquePaths(int m, int n) {
    if (m < 1 || n < 1)
        return 0;
    vector<int> m_path(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            m_path[j] += m_path[j - 1];
        }
    }
    return m_path[n - 1];
}