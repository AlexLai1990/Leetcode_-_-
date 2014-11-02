/*
 The normal DFS way will make time out.
 Solution 1:
    Using a DP array to pruning the process in the DFS
 
 If using work break I solution, it needs O(n^3) to create this 2D array. Because each round from s[i  to j] there is only its row’s info can be reuse. The direction is from left to right.
 To speed up and reuse the previous info, we can make the direction from right to the left. We need a vector<bool> insert_pos(s.length() + 1, false).
 
 2D: vector<vector<bool> > prev(s.length() + 1, vector<bool>
 Initial insert_pos[0] = true;
 From i  = 1 to s.length():
	From j = i – 1 to 0:
 If insert_pos(j) && substr(j, i- j) in dict. {
	Insert_pos(i) = true;  // using this vector to check previous string’s result
	Prev[i][j] = true;   //  j is the start index, i is the end
 }
 
 Solution 2:
 Way 2 use a hash table to store the previous result. It can speed up, when previous result can be result. It will go to the end first and store the previous for each index.
 It like the find all path from top left to bottom right.
 */

// Solution 1:
vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> m_ret;
    if (s == "" || dict.size() < 1)
        return m_ret;
    vector<bool> insert_pos(s.length() + 1, false);
    vector<vector<bool> > m_breaks(s.length() + 1, vector<bool> (s.length() , false) );
    insert_pos[0] = true;
    string curr;
    for (int i = 1; i <= s.length(); i++) {
        // from right to left
        for (int j = i - 1; j >= 0; j--) {
            curr = s.substr(j, i - j);
            if (insert_pos[j] && dict.find(curr) != dict.end()) {
                insert_pos[i] =  true;
                m_breaks[i][j] = true;
            }
        }
    }
    vector<string> m_path;
    // check from right to left, because we have s.length() + 1 row
    wordBreakHelper(s, m_breaks, m_ret, m_path , s.length());
    return m_ret;
}

void wordBreakHelper(const string &s, const vector<vector<bool> > &m_breaks,
                     vector<string> &m_ret, vector<string> &path, int end) {
    if (end == 0) {
        string tmp;
        for (auto iter = path.crbegin(); iter != path.crend(); ++iter)
            tmp += *iter + " ";
        tmp.erase(tmp.end() - 1);
        m_ret.push_back(tmp);
        return;
    }
    string curr;
    // i stands for where to cut and stands for 'j' in the m_breaks array
    for (int i = 0;  i < s.length(); i++) {
        if (m_breaks[end][i]) {
            curr = s.substr(i, end - i);
            path.push_back(curr);
            // the next end position is index i,
            // which will not include the char s[i], it contains from 0 - i-1
            // based on the m_breaks array start from row 1
            wordBreakHelper(s, m_breaks, m_ret, path , i);
            path.pop_back();
        }
    }
    return ;
}

// Solution 2:
vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> m_ret;
    if (s == "" || dict.size() < 1)
        return m_ret;
    string m_temp;
    unordered_map<int, vector<string> > m_memory;
    return wordBreakHelper(s, dict, m_temp, 0, m_memory);
}

vector<string> wordBreakHelper(const string &s, const unordered_set<string> &dict,
                               string temp, int start,
                               unordered_map<int, vector<string> > &memory) {
    vector<string> m_ret;
    if (memory.find(start) != memory.end() )
        return memory[start];
    // this will return NULL
    if (start == s.length())
        return m_ret;
    string curr;
    for (int len = 1; start + len <= s.length(); len++) {
        curr = s.substr(start, len);
        if (dict.find(curr) == dict.end())
            continue;
        else {
            if (start + len == s.length() )
                m_ret.push_back(curr);
            else {
                vector<string> m_suffix = wordBreakHelper(s, dict, temp + " " + curr, start + len, memory);
                // if the m_suffix is NULL, it will miss push curr
                // so we need add it when it comes to the length
                for (auto item : m_suffix) {
                    m_ret.push_back(curr + " " + item);
                }
            }
        }
    }
    memory[start] = m_ret;
    return m_ret;
}

