class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m_counts;
        vector<string> res;
        hash<string> mapping;
        int len = s.length(); 
        for (int i = 0; i <= len - 10; i++) {
            string key = s.substr(i, 10);
            int hash_val = mapping(key);
            auto check = m_counts.find(hash_val);
            if (check == m_counts.end()) 
                m_counts[hash_val] = 1; 
            else if (m_counts[hash_val] == 1) {
                res.push_back(key);
                m_counts[hash_val]++;
            }
        } 
        return res;
    }
};

// Solution2
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {  
        bitset<1048576> visit;
        unordered_set<string> temp;
        int len = s.length(); 
        for (int i = 0; i <= len - 10; i++) { 
            string curr = s.substr(i, 10);
            int test_index = convert_b(curr);
            if (visit.test(test_index))
                temp.insert(curr);
            else  { 
                visit.set(test_index);
            }
        }
        vector<string> res(temp.begin(), temp.end()); 
        return res;
    }
    
    int convert_b(string s) {
        int ret = 0;
        for (int i = 0; i < 10; i++) {
            ret = ret * 4 + decode(s[i]);
        }
        return ret;
    }
    
    int decode(char c) {
        switch (c) {
        	case 'A':
        		return 0;
        	case 'G':
        		return 1;
        	case 'C':
        		return 2;
        	case 'T':
        		return 3;
    	}
	    return -1;
    }
};