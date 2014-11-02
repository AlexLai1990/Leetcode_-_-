/*
 m_breaks[i] = for any j from 0 to i -1, the left side
 and right side exists in the dict
 */

bool wordBreak(string s, unordered_set<string> &dict) {
    if (dict.size() < 1)
        return false;
    vector<bool> m_breaks(s.length() + 1, false);
    // initialize from 0, because the whole length could be a word in dict
    m_breaks[0] = true;
    string right_side;
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1 ; j <= i; j++) {
            right_side = s.substr(i - j, j);
            if (m_breaks[i - j] &&
                dict.find(right_side) != dict.end()) {
                m_breaks[i] = true;
                break;
            }
        }
    }
    return m_breaks[s.length()];
}
