#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int k = 10;
void readLastKLine(const string &file_name) {
	ifstream in(file_name);
	string m_read[k];
	int index = 0;
	while (in.good()) {
		getline(in, m_read[index % k]);
		index++;
	}
	int start = index > k? (index % k) : 0;
	int count = min(k, index);
	for (int i = 0; i < count; i++) {
		cout << m_read[start + i] << endl;
	}
	
}