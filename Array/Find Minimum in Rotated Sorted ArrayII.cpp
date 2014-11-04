/*
 1. if 111 or 5 2 5 5 5 , the return condition for num[start] < num[end] will fail. So it needs end go previous position to next check. So the worst case fro II is O(N).
 2. And the update start and end position, needs to change. Like 1 2 3 3 3, when num[mid] <= num[end], set end = mid.

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
        else if (num[start] == num[end])
            end--;
        else if (num[mid - 1] > num[mid] && num[mid] < num[mid + 1])
            return num[mid];
        else if (num[mid] <= num[end])
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
