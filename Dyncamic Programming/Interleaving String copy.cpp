/*
 Using stack to store the index of ‘(‘.
 Check curr_len each time meets ‘)’.
	1. if (stack.empyt() )	reset accumulate_len.
	2. get curr_len:
       a) if stack has one ‘(‘ left, it needs to accumulate previous length.
       b) if stack has more than one left. curr_len = i – stack.top().
	3. Update max_len.
*/

int longestValidParentheses(string s) {
    int s_len = s.length();
    if (s_len <= 1)
        return 0;
    stack<int> m_left;
    int max_len = 0;
    // accumlate is used for record the continous length
    // it is used for update current length
    int accumulate_len = 0;
    int i = 0;
    while (i < s_len) {
        if (s[i] == '(') {
            m_left.push(i);
        }
        else {
            if (m_left.size() == 0) {
                accumulate_len = 0;
            }
            // check input: ( ()()
            else if(m_left.size() > 0) {
                int curr_len;
                if (m_left.size() == 1) {
                    curr_len = i - m_left.top() + 1;
                    m_left.pop();
                    accumulate_len += curr_len;
                    curr_len = accumulate_len;
                }
                // get correct of current length
                else if (m_left.size() > 1) {
                    m_left.pop();
                    curr_len = i - m_left.top();
                }
                if (curr_len > max_len)
                    max_len = curr_len;
            }
        }
        i++;
    }
    
    return max_len;
}