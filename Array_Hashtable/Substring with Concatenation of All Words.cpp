/*
 */

vector<int> findSubstring(string S, vector<string> &L) {
    size_t s_len = S.length();
    size_t l_len = L.size();
    size_t word_len = L[0].length();
    size_t words_len = l_len * word_len;
    vector<int> m_ret;
    if (s_len < words_len)
        return m_ret;
    unordered_map<string, int> m_dict;
    unordered_map<string, int> found;
    for (int i = 0; i < l_len; i++) {
        m_dict[L[i]]++;
    }
    for (int i = 0; i <= s_len - words_len; i++) {
        found = m_dict;
        int j;
        for (j = i; j <= i + words_len; j += word_len) {
            string curr = S.substr(j, word_len);
            auto pos = found.find(curr);
            if (pos == found.end() )
                break;
            if (--pos->second == 0)
                found.erase(pos);
        }
        // passed
        if (found.size() == 0)
            m_ret.push_back(i);
    }
    return m_ret;
}
