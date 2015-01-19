int count(int n, int deno[], int size) {
	if (n == 0)
		return 1;
	if (size == 0 || deno == NULL)
		return 0;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	int curr_deno;
	for (int i = 0; i < size; i++) {
		curr_deno = deno[i];
		for (int j = curr_deno; j <= n; j++) {
			dp[j] += dp[j - curr_deno];
		}
	}
	return dp[n];
}

int core_count(int n, int deno[], int size, int index);
int count_coins(int n, int deno[], int size) {
	if (n == 0)
		return 1;
	if (size == 0 || deno == NULL)
		return 0;
	return core_count(n, deno, size, 0);
}

int core_count(int n, int deno[], int size, int index) {
	if (n == 0)
		return 1;
	if (index >= size)
		return 0;
	int curr_deno = deno[index];
	int m_count = 0;
	for (int i = 0; curr_deno * i <= n; i++) {
		m_count += core_count(n - curr_deno * i, deno, size, index + 1); 
	}
	return m_count;
}
 
int main(int argc, char * argv[]){ 
	int deno[] = { 1, 2, 5};
	int coins = count(100, deno, sizeof(deno) / sizeof(deno[0]) );
	int coins2 = count_coins(100, deno, sizeof(deno) / sizeof(deno[0]));
	
	return 1;
}

/*
	test case:
	0, deno[], 2 = {1, 2}
	10, deno[], 2 = {1, 2}
	10, deno[], 3 = {1, 2, 5}
	100, deno[], 3 = {1, 2, 5}

*/