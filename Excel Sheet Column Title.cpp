class Solution {
public:
    string convertToTitle(int n) {
        if (n < 0)
            return ""; 
        string m_str = ""; 
        while (n > 0) {
            char temp = 'A' + (--n % 26);
            m_str = temp + m_str;
            n /= 26;
        }
        return m_str;
    }
};