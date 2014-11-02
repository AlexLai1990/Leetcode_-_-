/*
s : dfae a bdd
p : *a
p : dfae ? bdd
*/

// recursion will run out of time
recur_wildcard(const * s, const *p) {
	if (s == NULL)
		return p == NULL;
	// might have corner case: "" "*", "" "*a*"
	/* 
	if (*s == '\0')
		return *p == '\0';
	*/
	// the s could have *
	/*
	if (*p != '*') {
		if (*s == *p || (*p == '?' && *s != '\0')) 
			return recur_wildcard(s++, p++);
		else
			return false;
	} */
	else if (*s == *p || (*s != '\0' && *p == '?'))
		return recur_wildcard(s + 1, p + 1);
	else if (*p == '*') {
		// skip all possible * in p
		while (*p != '\0' && *p == '*') {
			p++;
		}
		if (*p == '\0')
			return true;
		// current p is pointer to the char which is next of *
		while (*s != '\0') {
			if (recur_wildcard(s, p) == true)
				return true;
			s++;
		}
		return false;
	}
} 

/*
 *  fdesa  *?a	
 */
bool isMatch(const char *s, const char *p) {  
	if (s == NULL)
		return s == p; 
	const char *pre_s = NULL;
	const char *pre_p = NULL;
	bool star_flag = false;
	// scan s to the end and check whether p is end or not
	while (*s != '\0') {
		if (*s == *p || *p == '?') {
			s++;
			p++;
			continue;
		}
		else if (*p == '*') {
			// skip all possible * and find the next non-* char
			while (*p != '\0' && *p == '*')
				p++;
			if (*p == '\0')
				return true;
			pre_s = s;
			pre_p = p;
			star_flag = true;
		}
		else if (star_flag) {
			pre_s++;
			s = pre_s;
			p = pre_p;
		}
		else 
		    return false;
	}
	while (*p != '\0' && *p == '*')
		p++;
	return *p == '\0';
}

