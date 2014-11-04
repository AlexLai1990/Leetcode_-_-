/*
   HashTable to count each expected char.
   When it comes to right size, update the minimum window.
 */

string minWindow(string S, string T) {
    if (S.size() < 1 || S.size() < T.size())
        return "";
    int expect[256];
    int appear[256];
    memset(expect, 0, sizeof(expect));
    memset(appear, 0, sizeof(appear));
    int left = 0, right = 0;
    int count = 0;
    int min_window = INT_MAX;
    int min_start = 0;
    for (int i = 0; i < T.size(); i++) {
        expect[T[i] - '\0']++;
    }
    int i = 0;
    while (i <= S.size() - 1) {
        if (expect[S[i] - '\0'] > 0) {
            appear[S[i] - '\0']++;
            if (appear[S[i] - '\0'] <= expect[S[i] - '\0'])
                count++;
        }
        if (count == T.size()) {
            right = i;
            while(appear[S[left] - '\0'] > expect[S[left] - '\0'] || expect[S[left] - '\0'] == 0) {
                appear[S[left] - '\0']--;
                left++;
            }
            if (min_window > right - left + 1) {
                min_window = right - left + 1;
                min_start = left;
            }
        }
        i++;
    }
    return min_window == INT_MAX ? "" : S.substr(min_start, min_window);
}
