/*
 Space O(N) Time O(N^2)
 */

int numTrees(int n) {
    if (n < 2)
        return n;
    vector<int> m_count(n + 1, 0);
    m_count[0] = 1;
    m_count[1] = 1;
    for (int i = 2; i <= n; i++) {
        int temp  = 0;
        for (int j = 1; j <= i; j++) {
            temp += m_count[j - 1] * m_count[i - j];
        }
        m_count[i] = temp;
    }
    return m_count[n];
}
