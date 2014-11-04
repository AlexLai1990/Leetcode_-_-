/*
  Solution1, Using strtok to get all words, O(N), or using a stack to store the words.
  Solution 2, in-place O(1). Using reverse function to reverse each word, and reverse the all string in the end.
 */

// Solution 1
#include <string.h>
  
void reverseWords(string &s) {
    if (s.length() < 1)
        return ;
    int i = 0;
    int s_len = s.length();
    vector<string> m_words = getWords(s);
    string m_ret;
    for (int i = m_words.size() - 1; i >= 0; i--) {
        m_ret.append(m_words[i]);
        m_ret += " ";
    }
    if (m_ret.length() > 1)
        m_ret.resize(m_ret.length()- 1);
    s = m_ret;
    return;
}

vector<string> getWords(string &s) {
    char *str = (char*)s.c_str();
    vector<string> m_ret;
    char *pch;
    pch = strtok(str, " ");
    while (pch != NULL) {
        m_ret.push_back(string(pch));
        pch = strtok(NULL, " ");
    }
    return m_ret;
}

// Solution 2
void reverseWords(string &s) {
    if (s.length() < 1)
        return ;
    int start = 0;
    while (start < s.length() && s[start] == ' ') {
        start++;
    }
    int m_start = start;
    int end = start;
    while (end < s.length()) {
        // find the end of curr word
        while (end < s.length() && s[end] != ' ')
            end++;
        reverseWord(s, start, end - 1);
        // set new start, end point to first space now
        while (start < end && s[start] != ' ')
            start++;
        start++;
        // pass the following spaces
        while (end < s.length() && s[end] == ' ')
            end++;
    }
    --end;
    while (s[end] == ' ')
        --end;
    s = s.substr(m_start, end - m_start + 1);
    reverseWord(s, 0, s.length() - 1);
}