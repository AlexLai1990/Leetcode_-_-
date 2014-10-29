/*
 Solution 1 recursion.
 1.	check len3 = len1 + len2
 2.	dfsHelper(index1, end_1, index2, end_2, index3, end3) {
 if (index3 == end3)
	return index1 == end_1 && index2 == end_2;
	return dfsHelper(index1++, end_1, index2, end_2, index3, end3)
            || dfsHelper(index1, end_1, index2++, end_2, index3, end3)
 }
 Solution 2 DP.
 2D state means current s3[I + j – 1] is isinterleave or not.
 It depends on the previous result(left or right) and checking result of the last char in s3 and s1(s2).
*/

bool isInterleave(string s1, string s2, string s3) {
    int s1_len = s1.length();
    int s2_len = s2.length();
    int s3_len = s3.length();
    if (s1_len + s2_len != s3_len)
        return false;
    vector<vector<int> > isInterleaveSet(s1_len + 1, vector<int>(s2_len + 1, false));
    isInterleaveSet[0][0] = true;
    for (int i = 1; i <= s2_len; i++) {
        if (s2[i - 1] == s3[i - 1])
            isInterleaveSet[0][i] = true;
    }
    for (int i = 1; i <= s1_len; i++) {
        if (s1[i - 1] == s3[i - 1])
            isInterleaveSet[i][0] = true;
    }
    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            isInterleaveSet[i][j] = (isInterleaveSet[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) ||
            (isInterleaveSet[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
        }
    }
    return isInterleaveSet[s1_len][s2_len];
}