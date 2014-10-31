/*
 Using a preprocessed 2D array to store the palindrome state of that string.
 m_palindrome_set[i][j] means is whether s.substr(i, j) is a palindrome.
 */

int minCut(string s) {
    int s_len = s.length();
    if (s_len <= 1)
        return 0;
    vector<vector<bool> > m_palindrome_set = prepocess_palindrome(s);
    vector<int> m_cuts(s_len + 1, INT_MAX);
    // we might not need a cut for whole word.
    m_cuts[0] = -1;
    for (int i = 1; i < s_len + 1; i++) {
        // check all possible palindrome substring from i - j, to i - 1
        // j stands for length
        for (int j = 1; j <= i; j++) {
            if (m_palindrome_set[i - j][i - 1] == true) {
                m_cuts[i] = min(m_cuts[i], m_cuts[i - j] + 1);
            }
        }
    }
    return m_cuts[s_len];
}

vector<vector<bool> > prepocess_palindrome(const string &s) {
    int s_len = s.length();
    vector<vector<bool> > m_ret(s_len, vector<bool> (s_len, false));
    for (int i = 0; i < s_len; i++) {
        m_ret[i][i] = true;
        if (i + 1 < s_len && s[i + 1] == s[i]) {
            m_ret[i][i + 1] = true;
        }
    }
    for (int i = s_len - 3; i >= 0 ; i--) {
        for (int j = s_len - 1; j >= i + 2; j--) {
            if (m_ret[i + 1][j - 1] && s[i] == s[j])
                m_ret[i][j] = true;
        }
    }
    return m_ret;
}