/*
 Divide and conquer: with recursion function (start, end) to get the sub result.
 */


vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> m_ret;
    if (n < 1) {
        m_ret.push_back(NULL);
        return m_ret;
    }
    return generateTreesHelper(1, n);
}

vector<TreeNode *> generateTreesHelper(int left, int right) {
    if (left > right) {
        vector<TreeNode *> m_ret;
        m_ret.push_back(NULL);
        return m_ret;
    }
    vector<TreeNode *> m_ret;
    for (int i = left; i <= right ; i++) {
        vector<TreeNode *> m_left = generateTreesHelper(left, i - 1);
        vector<TreeNode *> m_right = generateTreesHelper(i + 1, right);
        for (int j= 0; j < m_left.size(); j++) {
            for (int k = 0; k < m_right.size(); k++) {
                TreeNode *m_new = new TreeNode (i);
                m_new->left = m_left[j];
                m_new->right = m_right[k];
                m_ret.push_back(m_new);
            }
        }
    }
    return m_ret;
}