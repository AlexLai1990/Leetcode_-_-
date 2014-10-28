// recursion will run out of time for LC OJ
bool isMatch(const char *s, const char *p) {
	if (s == NULL)
		return p == NULL;
	else if (p == NULL)
		return true;
	else if (*s == '\0')
		return *p == '\0';
	else if (*s == *p || *p == '?')
		isMatch(s + 1, p + 1);
	else if (*p == '*') {
		// get the next char after '*'
		while (*p == '*')
			p++;
		if (*p == '\0')
			return true;
		while (*s != '\0' && !isMatch(s, p))
			s++;
		return s != '\0';
	}
	else 
		return false;
}


/*
Using Iteration. O(N*M)
If it has star, because it mismatches, just move the pre_pos_s to next.
This means that put the previous pre_pos_s to match with the star.
This way is to fix the * position in p string. And then move s, use pre_pos_s. 
Sooner or later, s will go to the end. And then check the p pointer.
*/
bool isMatch(const char *s, const char *p) {
	if (s == NULL)
		return p == NULL;
	else if (p == NULL)
		return true;
	/* this will not work for  s = '', p = '*a*'
	   it needs to skip all previous * in p.
	else if (*s == '\0')
		return *p == '\0' || *p == '*';
	*/
	const char *pre_pos_s = NULL;
	const char *pre_pos_p = NULL;
	bool star_flag = false;
	while (*s != '\0') {
		if (*s == *p || *p == '?') {
			s++;
			p++;
		}
		else if (*p == '*'){
			star_flag = true;
			while (*p == '*') {
				p++;
			}
			if (*p == '\0')
				return true;
			pre_pos_s = s;
			pre_pos_p = p;
		}
		// if current having valid *, check next s
		// each time update the next s, and reset the p
		else if (star_flag) {
			pre_pos_s++;
			s = pre_pos_s;
			p = pre_pos_p;
		}
		// if there is no way to matching string from next char of '*'
		// return false
		else
			return false;
	}
	// skip all following possible '*'s
	while (*p == '*')
		p++;
	return *p == '\0';
}









