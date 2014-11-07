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

/*
Node *deepCopyNode(Node * node) {
	if (node == NULL);
		return ;
	unorderedmap<Node *, Node *> m_dict;
	return	deepCopyNodeHelper(node, m_dict);
}

Node *deepCopyNodeHelper(Node * curr, unorderedmap<Node *, Node *> & m_dict) {
	if (curr == NULL)
		return NULL;
	if (m_dict.find(curr) != m_dict.end()) {
		return m_dict[curr];
	}
	Node * m_new = new Node();
	m_dict[curr] = m_new;
	m_new->left = deepCopyNodeHelper(curr->left, m_dict);
	m_new->right = deepCopyNodeHelper(curr->right, m_dict);
	return m_new;
}

*/