/*
 Naïve thought: check every possible rectangle in  each point. O(N^4) O(1)
 DP O(N^2) O(N)
 Take each row as a histogram, and try to get max_area row by row.
*/

int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.size() < 1)
        return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> m_histogram(col, 0);
    int m_max = 0;
    for (int i = 0; i < row; i++) {
        int curr_max = 0;
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == '1')
                m_histogram[j] += 1;
            else
                m_histogram[j] = 0;
        }
        curr_max = get_maxAreaInHistogram(m_histogram);
        if (curr_max > m_max)
            m_max = curr_max;
    }
    return m_max;
}

int get_maxAreaInHistogram(vector<int> hist) {
    if (hist.size() < 1)
        return 0;
    hist.push_back(-1);
    int max_area = 0;
    stack<int> m_stack;
    int i = 0;
    while (i < hist.size()) {
        if (m_stack.empty() || hist[m_stack.top()] <= hist[i])
            m_stack.push(i++);
        else {
            int height = hist[m_stack.top()];
            m_stack.pop();
            int width = m_stack.empty() ? i : i - m_stack.top() - 1;
            int area = height * width;
            if (area > max_area)
                max_area = area;
        }
    }
    return max_area;
}