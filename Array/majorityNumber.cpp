class Solution {
public:
    int majorityElement(vector<int> &num) {
        int m_majority, count = 0;
        for (int i = 0; i < num.size(); i++) {
            if (count == 0) {
                m_majority = num[i];
                count++;
            }
            else if (m_majority == num[i]) {
                count++;
            }
            else {
                count--;
            }
        }
        return m_majority;
    }
};