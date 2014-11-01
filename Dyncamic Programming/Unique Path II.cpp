/*
 DP
 better to initialize the value for first row.
 And then do for loop from 1 – row - 1; And think about the first column situation.

 */

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int row = obstacleGrid.size();
    if (row < 1)
        return 0;
    int col = obstacleGrid[0].size();
    vector<int> m_state(col, 0);
    // initilize m_state based on first row
    for (int i = 0; i < col; i++) {
        if (obstacleGrid[0][i] != 1)
            m_state[i] = 1;
        else
            break;
    }
    // after initilization, we count from next row
    for (int i = 1; i < row; i++) {
        // first col could have 1, so we check value in each col
        for (int j = 0; j < col; j++) {
            if (obstacleGrid[i][j] == 1)
                m_state[j] = 0;
            else if (j - 1 >= 0)
                m_state[j] += m_state[j - 1];
        }
    }
    
    return m_state[col - 1];
}