/*
 Determine the return condition first.
 Compare mid and right to set the start and end position.
 */

int findMin(vector<int> &num) {
    int m_min = INT_MAX;
    int start = 0;
    int end = num.size() - 1;
    int mid = 0;
    while(start + 1 < end) {
        mid = start + (end - start) / 2;
        if (num[start] < num[end])
            return num[start];
        else if (num[mid - 1] > num[mid] && num[mid] < num[mid + 1])
            return num[mid];
        else if (num[mid] < num[end])
            end = mid;
        else if (num[mid] > num[end])
            start = mid;
    }
    if (num[start] < num[end])
        m_min = num[start];
    else
        m_min = num[end];
    return m_min;
}
