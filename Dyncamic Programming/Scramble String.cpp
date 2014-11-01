/* 
 Solution 1 : DFS + Pruning
 Solution 2 : DP
 Idea : http://blog.sina.com.cn/s/blog_b9285de20101gy6n.html
 Using a 3D array, to store the inner scramble string for (s1 and s2).
 Scramble_set[i][j][m_len] means whether it is scramble strings for (s1[i – m_len], s2[j – m_len]).
 Update:
	Scramble_set[i][j][m_len]  =  true
 1. s1[i – m_len] == s2[j – m_len]
	2. for any length k between (1, m_len):
 s1[ I –> k] == s2[ j –> k] && s1[i + k –> end] == s2[j + k –> end]
 || s1[I –> k] == s2[I + m_len – k -> end] && s1[s + m_Len – k -> end] == s[j ->k]
 This equation can reuse the previous 3D array.

 */

// DFS + Pruning:
bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;
    if (s1 == s2)
        return true;
    // pruning with a char set
    vector<int> m_chars (26, 0);
    for (int i = 0; i < s1.length(); i++) {
        m_chars[s1[i] - 'a'] += 1;
        m_chars[s2[i] - 'a'] -= 1;
    }
    for (int i = 0; i < 26; i++){
        if (m_chars[i] != 0)
            return false;
    }
    
    for (int i = 1; i <= s1.length() - 1; i++) {
        string s11 = s1.substr(0, i);
        string s12 = s1.substr(i);
        string s21 = s2.substr(0, i);
        string s22 = s2.substr(i);
        string s31 = s2.substr(s2.length() - i);
        string s32 = s2.substr(0, s2.length() - i);
        
        if ((isScramble(s11, s21) && isScramble(s12, s22) )||
            (isScramble(s11, s31) && isScramble(s12, s32) ))
            return true;
    }
    return false;
}

// DP ways: O(N^3) O(N^3)
bool isScramble(string s1, string s2) {
    int s1_len = s1.length();
    int s2_len = s2.length();
    if (s1_len != s2_len)
        return false;
    bool scramble_set[s1_len][s2_len][s1_len + 1];
    memset(scramble_set, false, sizeof(scramble_set));
    for (int i = s1_len - 1; i >= 0; i--) {
        for (int j = s2_len - 1; j >= 0; j--) {
            for (int m_len = 1; m_len <= s1_len && i + m_len <= s1_len && j + m_len <= s1_len ; m_len++) {
                string s1_temp = s1.substr(i,m_len);
                string s2_temp = s2.substr(j,m_len);
                if (s1_temp == s2_temp)
                    scramble_set[i][j][m_len] = true;
                else {
                    // update scramble_set[i][j][m_len] to check possible scramble based on different previous lengths
                    for (int k = 1; k < m_len; k++) {
                        if (scramble_set[i][j][k] && scramble_set[i + k][j + k][m_len - k] ||
                            scramble_set[i][j + m_len - k][k] && scramble_set[i + k][j][m_len - k]) {
                            scramble_set[i][j][m_len] = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    return scramble_set[0][0][s1_len];
}