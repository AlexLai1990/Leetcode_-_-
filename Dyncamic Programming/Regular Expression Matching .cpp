/* 
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 */

bool isMatch(const char *s, const char *p) {
    if (p == NULL)
        return s == NULL;
    if (*p == '\0')
        return *s == '\0';
    if (*(p + 1) != '*') {
        if (*p == *s || (*p == '.' && *s != '\0'))
            return isMatch(s + 1, p + 1);
        else
            return false;
    }
    // if the next char of p is *
    else {
        // because it does not match, skip the previous p
        if (*p != *s && *p != '.') {
            return isMatch(s, p + 2);
        }
        else {
            // jump all *p == *s
            while (*p == *s || (*p == '.' && *s != '\0')) {
                // check by pass the next star
                if (isMatch(s, p + 2))
                    return true;
                s++;
            }
            return isMatch(s, p + 2);
        }
    }
}