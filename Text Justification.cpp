/*
 Two functions:
 1. Count how many words can put into a line.
 2.  Return Central Alignmented string.
    a)	If this could be the last line, just add one space to each word.
    b)	Else need to get the different spaces for each words from left to right.
    c)	Add the following space for the empty space based on width.
 */

vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> m_ret;
    if (words.size() < 1)
        return m_ret;
    int i = 0;
    int start_index;
    while (i < words.size()) {
        string curr;
        int curr_count = 0;
        int curr_len = 0;
        start_index = i;
        // try to put as many words as possible
        while (i < words.size() && curr_len + curr_count + words[i].length() <= L) {
            curr = words[i];
            curr_count++;
            curr_len += curr.length();
            i++;
        }
        // input the number of slot
        string m_output = centerAlignment(words, start_index, curr_count, curr_len, L);
        m_ret.push_back(m_output);
    }
    return m_ret;
}

string centerAlignment(vector<string> &words, int start, int count, int curr_len, int width) {
    string m_ret;
    m_ret = words[start];
    // adding space
    // i stands for distance, i - 1 stands for index
    for (int i = 1; i < count; i++) {
        // this is the last line
        if (start + count >= words.size()) {
            m_ret += " ";
        }
        else {
            m_ret += string((width - curr_len) / (count - 1) + (i - 1 < (width - curr_len) % (count - 1 )), ' ');
        }
        m_ret += words[start + i];
    }
    m_ret += string(width - m_ret.length(), ' ');
    return m_ret;
}
