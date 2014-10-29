/*
The state matrix means: how many minimum distance from current word1[0..i] to word2[0..j].
*/

int minDistance(string word1, string word2) {
    int size_word1 = word1.length();
    int size_word2 = word2.length();
    vector<vector<int> > m_distance(size_word1 + 1, vector<int>(size_word2 + 1, 0));
    int curr_dist;
    for (int i = 1; i <= size_word2; i++) {
        m_distance[0][i] = i;
    }
    for (int j = 1; j <= size_word1; j++) {
        m_distance[j][0] = j;
    }
    for (int i = 1; i <= size_word1; i++) {
        for (int j = 1; j <= size_word2; j++) {
            // these two conditions means replacing, adding a new word or deleting a word
            curr_dist = min(m_distance[i - 1][j], m_distance[i][j - 1]) + 1;
            if (word1[i - 1] == word2[j - 1]) {
                m_distance[i][j] = min(curr_dist, m_distance[i - 1][j - 1]);
            }
            // directly adding new word
            else {
                m_distance[i][j] = min(curr_dist, m_distance[i - 1][j - 1] + 1);
            }
        }
    }
    return m_distance[size_word1][size_word2];
}