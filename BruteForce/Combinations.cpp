class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > m_ret;
        if (n < k)
            return m_ret; 
        
        vector<int> curr;
        combineHelper(m_ret, curr, 1, k, n); 
        return m_ret;
    }
    
    void combineHelper(vector<vector<int> > &m_ret, vector<int> curr, int start, int k, int n) {
        if (curr.size() == k) {
            m_ret.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) { 
            curr.push_back(i);
            combineHelper(m_ret, curr, i + 1, k, n);
            curr.pop_back();
        }
        return;
    }
};