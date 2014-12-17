class Solution {
public:
    int maximumGap(vector<int> &num) {
    	if (num.size() < 2)
    		return 0;
    	int len = num.size();
    	int m_max = *max_element(num.begin(), num.end());
    	int m_min = *min_element(num.begin(), num.end());
    
    	// so that the difference in each bucket cannot larger than len - 1
    	int gap = (int)ceil((double)(m_max - m_min) / (len - 1));
    	int bucketSize = (int)ceil((double)(m_max - m_min) / gap) + 1;
    	vector<int> bucketMin(bucketSize, INT_MAX);
    	vector<int> bucketMax(bucketSize, INT_MIN);
    
    	int index_bucket = 0;
    	for (int i = 0; i < len; i++) {
    		index_bucket = (num[i] - m_min) / gap;
    		bucketMin[index_bucket] = min(bucketMin[index_bucket], num[i]);
    		bucketMax[index_bucket] = max(bucketMax[index_bucket], num[i]);
    	}
    
    	int m_max_gap = INT_MIN;
    	int prev_max = m_min;
    	for (int i = 0; i < bucketSize; i++) {
    		if (bucketMin[i] != INT_MAX && bucketMax[i] != INT_MIN) {
    			m_max_gap = max(m_max_gap, bucketMin[i] - prev_max);
    			prev_max = bucketMax[i];
    		}
    	}
    
    	m_max_gap = max(m_max_gap, m_max - prev_max);
    	return m_max_gap;
    }
};