int elimatevowel(char *a) {
	if (a == NULL)
		return 0;	
	int size = strlen(a);
	string check = "aeiou";
	int curr = 0, m_size = 0;
	for (int i = 0; i < size; i++) {
		if (check.find_first_of(a[i]) == string::npos) { 
			a[m_size++] = a[i];
		} 
	}
	return m_size;
}
int main() {
	char m_s[] = "abcdefg";
	int str_size = strlen(m_s);
	// int m_test = elimatevowel(m_s, sizeof(m_s) / sizeof(m_s[0])); it has one more space of 
	int m_test = elimatevowel(m_s); 
	return 1;
}