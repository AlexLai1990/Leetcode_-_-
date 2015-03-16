class SuffixTreeNode {
public:
	vector<int> index;
	char val;
	unordered_map<char, SuffixTreeNode*> children;

	SuffixTreeNode() {}

	void insert(string s, int pos) {
		index.push_back(pos);
		if (s.length() != 0) {
			char curr = s[0];
			SuffixTreeNode *child = NULL;
			if (children.find(curr) == children.end()) {
				child = new SuffixTreeNode();
				children[curr] = child;
			}
			else {
				child = children[curr];
			}
			string remains = s.substr(1);
			child->insert(remains, pos);
		}
	}

	vector<int> search(string s) {
		if (s == "")
			return index;
		else {
			char curr = s[0];
			if (children.find(curr) == children.end()) {
				vector<int> res;
				return res;
			}
			else {
				string remains = s.substr(1);
				SuffixTreeNode *child = children[curr];
				return child->search(remains);
			}	
		}
	} 
};

class SuffixTrees {
public:
	SuffixTreeNode * root = new SuffixTreeNode();
	SuffixTrees(string s) {
		for (int i = 0; i < s.length(); i++) {
			string sub = s.substr(i);
			root->insert(sub, i);
		}
	}
	vector<int> searchString(string s) {
		return root->search(s);
	}
};

int main() {

	SuffixTrees *st = new SuffixTrees("bibs");
	vector<int> search_res = st->searchString("b");

	search_res = st->searchString("bs");
	search_res = st->searchString("ib");
	search_res = st->searchString("ibs");
	search_res = st->searchString("bibs");	
}
