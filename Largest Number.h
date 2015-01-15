class Solution {
public: 
    string largestNumber(vector<int> &num) {
        string m_res = "";
        if (num.size() < 1)
            return m_res;  
        sort(num.begin(), num.end(), [&](int num1, int num2) { 
            string s1 = to_string(num1);
            string s2 = to_string(num2);
            return s1 + s2 > s2 + s1;
        });
        if (num[0] == 0)
            return "0";
        for (int i = 0; i < num.size(); i++) {
            m_res += to_string(num[i]);
        }
        return m_res;
    }
};