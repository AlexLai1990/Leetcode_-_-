int lengthOfLongestSubstringTwoDistinct(string s) {
	int s_len = s.length();
	// start_index for length
	int i = 0;
	// stands for the index of last first different char 
	int j = -1;
	int max_len = 0;
	for (int k = 1; k < s_len; k++) {
		if (s[k] == s[k - 1])
			continue;
		else {
			if (j >= 0 && s[k] != s[j]) {
				max_len = max(max_len, k - i);
				i = j + 1; 
			}
			j = k - 1;
		}
	}
	return max(max_len, s_len - i);
}