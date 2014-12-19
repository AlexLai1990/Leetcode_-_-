class Solution {
public:
    int compareVersion(string version1, string version2) {
    	if (version1 == "" || version2 == "")
    		return -1;
    	int v1_start = 0, v2_start = 0;
    	while (v1_start < version1.length() || v2_start < version2.length()) {
    		int v1_len = getLength(version1, v1_start);
    		int v2_len = getLength(version2, v2_start);
    		if (v1_len > v2_len)
    			return 1;
    		else if (v1_len < v2_len)
    			return -1;
    		else {
    			for (int i = 0; i < v1_len; i++) {
    				if (version1[v1_start] > version2[v2_start])
    					return 1;
    				else if (version1[v1_start] < version2[v2_start])
    					return -1;
    				v1_start++;
    				v2_start++;
    			}
    			v1_start++;
    			v2_start++;
    		}
    	}
    	return 0;
    }
    
    int getLength(const string &v, int &start) {
    	int len = v.length();
    	// skip all possible '0's 
    	// We need to check them as int even after '.'
    	while (start < len && v[start] == '0')
    		start++;
    	int count = start;
    	while (count < len && v[count] != '.') {
    		count++;
    	}
    	return count - start;
    }
};
