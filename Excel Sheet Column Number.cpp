class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length(); 
        int m_res = 0;
        for (int i = 0; i < len; i++) {
            m_res *= 26;
            m_res += (s[i] - 'A' + 1) ;
        }
        return m_res;
    }
};