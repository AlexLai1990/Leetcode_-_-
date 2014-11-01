/* 
 Solution 1: Using a temp array to store the info of previous row.
 Space O(N) Time O(N^2)
 Solution 2:
 Space O(1) in-place Time(O^2)
 */

// Solution 1:
int minimumTotal(vector<vector<int> > &triangle) {
    int size = triangle.size();
    if (size < 1)
        return 0;
    vector<int> m_result(size, 0);
    vector<int> m_temp = m_result;
    m_result[0] = triangle[0][0];
    int min_result = INT_MAX;
    for (int i = 1; i < size; i++) {
        m_temp = m_result;
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                m_result[j] = triangle[i][0] + m_temp[j];
                continue;
            }
            if (j == i) {
                m_result[j] = triangle[i][j] + m_temp[j - 1];
                continue;
            }
            m_result[j] = min(m_temp[j - 1], m_temp[j]) + triangle[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        if (min_result > m_result[i])
            min_result = m_result[i];
    }
    return min_result;
}

// Solution 2:
int minimumTotal(vector<vector<int> > &triangle) {
    int size = triangle.size();
    if (size < 1)
        return 0;
    int min_result = INT_MAX;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                triangle[i][0] += triangle[i - 1][0];
                continue;
            }
            if (j == i) {
                triangle[i][j] += triangle[i - 1][j - 1];
                continue;
            }
            triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
    }
    
    for (int i = 0; i < size; i++) {
        if (min_result > triangle[size - 1][i])
            min_result = triangle[size - 1][i];
    }
    return min_result;
}