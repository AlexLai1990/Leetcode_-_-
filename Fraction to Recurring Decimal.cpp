class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	if (denominator == 0)
    		return "";
    	if (numerator == 0)
    	    return "0";
    	string m_res;
    	bool negative = ((numerator ^ denominator) >> 31 & 1 ) > 0 ? true : false;
    	long long m_numerator = abs((long long)numerator);
    	long long m_denominator = abs((long long)denominator);
    	long long int_part = m_numerator / m_denominator;
    	long long left = m_numerator % m_denominator;
    	vector<int> float_part;
    	unordered_map<int, int> check_dig;
    	int curr_float, count = 0;
    	while (left != 0 && check_dig.find(left) == check_dig.end()) {
    		check_dig[left] = count++;
    		left *= 10;
    		curr_float = left / m_denominator;
    		float_part.push_back(curr_float);
    		left %= m_denominator;
    	}
    	if (left == 0) {
    		m_res = to_string(int_part);
    		if (float_part.size() != 0) {
    			m_res += ".";
    			for (int i = 0; i < float_part.size(); i++) {
    				m_res += to_string(float_part[i]);
    			}
    		}
    	}
    	else {
    		m_res = to_string(int_part) + ".";
    		string m_float = "";
    		for (int i = 0; i < float_part.size(); i++) {
    			m_float += to_string(float_part[i]);
    		}
    		int no_recur = check_dig[left];
    		string m_float_no_rec = m_float.substr(0, no_recur);
    		string m_float_rec = m_float.substr(no_recur);
    		m_res = m_res + m_float_no_rec + "(" + m_float_rec + ")";
    	}
    	if (negative)
    		m_res = "-" + m_res;
    	return m_res;
    }
};