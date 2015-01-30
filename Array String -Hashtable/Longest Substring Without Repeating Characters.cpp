class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int s_len = s.length(); 
    	int i = 0, j = 0;
    	int max_len = 0;
    	// assume that all lowercase char 
    	int *m_visit = new int[256];
	    memset(m_visit, -1, 256 * sizeof(int));
	    int prev_index = -1;
	    while (j < s_len) {
	        prev_index = m_visit[s[j] - '\0'];
	        // visited before, and i need to be valid
	        if (prev_index >= i) {
	            i = prev_index + 1;
	        } 
	        m_visit[s[j] - '\0'] = j;
            max_len = max(max_len, j - i + 1);
	        j++;
	    }
    	delete[] m_visit;
    	return max_len;
    }
};