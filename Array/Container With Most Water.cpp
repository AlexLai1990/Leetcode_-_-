int maxArea(vector<int> &height) {
    if (height.size() < 2)
        return 0;
    int left = 0;
    int size = height.size();
    int right = size - 1;
    int max_area = 0;
    int m_height = 0;
    int m_width = 0;
    int m_area = 0;
    while (left < right && left < size && right < size) {
        m_width = right - left; 
        // move the less one
        if (height[left] > height[right]) {
            m_height = height[right];
            right--;
        }
        else {
            m_height = height[left]; 
            left++;
        } 
        m_area = m_height * m_width; 
        if (m_area > max_area)
            max_area = m_area;
    }
    return max_area;
}