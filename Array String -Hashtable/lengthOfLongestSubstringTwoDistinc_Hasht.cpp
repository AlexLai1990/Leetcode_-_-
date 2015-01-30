int lengthOfLongestSubstringTwoDistinct2(string s) {
	int s_len = s.length();
	int *count = new int[256];
	memset(count, 0, 256 * sizeof(int));
	int i = 0;
	int dif_size = 0;
	int max_len = 0;
	for (int j = 0; j < s_len; j++) {
		int curr = s[j] - '\0';
		if (count[curr] == 0) {
			dif_size++; 
		}
		count[curr]++;
		while (dif_size > 2) {
			count[s[i] - '\0']--;
			if (count[s[i] - '\0'] == 0) { 
				dif_size--;
			}
			i++;
		} 
		max_len = max(max_len, j - i + 1);
	}
	delete count;
	return max_len;
}