/*
 Col: input string
 Row: pattern string
 Matrix[i][j]: in s[0…j] how many distinct subsequence in s can match p[0..i].
 P[0..i] needs to be all matched.
 For example:
	S: rabbb p: rabb
 I = 3, j = 4.
 If(p[i-1] == s[j-1])
	Count = (rabb -  rab) + (rabb- rabb)
	Count = the ways of using that input char + not using new input char(but still matching current P)
 If (p[i-1] != s[j-1])  Count = (rabb – rabb)  get previous matching. The new char in s is useless.
*/

int numDistinct(string S, string T) {
    int s_len = S.length();
    int t_len = T.length();
    // using sub_counts[i][j] to track matching of S[0 - j] and T[0 - i]
    vector<vector<int> > sub_counts(t_len + 1, vector<int> (s_len + 1, 0));
    for (int i = 0; i <= s_len; i++) {
        // as for T is "", it will return 1
        sub_counts[0][i] = 1;
    }
    for (int i = 1; i <= t_len; i++) {
        // as for S is "", it will return 0;
        sub_counts[i][0] = 0;
    }
    for (int i = 1; i <= t_len; i++) {
        for (int j = 1; j<= s_len; j++) {
            if (T[i - 1] == S[j - 1])
                sub_counts[i][j] = sub_counts[i][j - 1] + sub_counts[i - 1][j - 1];
            else
                sub_counts[i][j] = sub_counts[i][j - 1];
        }
    }
    return sub_counts[t_len][s_len];
}