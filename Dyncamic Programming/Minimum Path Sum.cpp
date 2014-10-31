/*
 2D DP.
 M_state[i][j] = min(m_state[i][j-1], m_state[I – 1][j]) + 2D[i][j].
 1D DP. Using rolling array from left to right.
 M_State[I + 1] = min(m_state[I], m_state[I + 1]) + 2D[i][j].
 */

int minPathSum(vector<vector<int> > &grid) {
    int row = grid.size();
    if(row < 1)
        return 0;
    int col = grid[0].size();
    vector<int> m_path(col, 0);
    // initialize first row
    m_path[0] = grid[0][0];
    for (int i = 1; i < col; i++) {
        m_path[i] = grid[0][i] + m_path[i - 1];
    }
    // care about the first column
    for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0) {
                m_path[j] += grid[i][0];
            }
            else {
                m_path[j] = min(m_path[j - 1], m_path[j]) + grid[i][j];
            }
        }
    }
    return m_path[col - 1];
}