int findPeakElement(const vector<int> &num) {
    int ret_index = 0;
    if (num.size() < 2)
        return ret_index;
    int start = 0, end = num.size() - 1;
    int mid;
    while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (mid - 1 >= 0 && mid + 1 <= num.size() -1 && 
            num[mid - 1] < num[mid] && num[mid] > num[mid + 1])
            return mid;
        else if (mid + 1 <= num.size() - 1 && num[mid] < num[mid + 1])
            start = mid;
        else if (mid - 1 >= 0 && num[mid] < num[mid - 1])
            end = mid;
    }
    if (start == 0 && num[start] > num[end])
        return start;
    else if (end == num.size() - 1 && num[start] < num[end])
        return end;
        
    if (num[start - 1] < num[start] && num[start] > num[end])
        return start;
    if (num[start] < num[end] && num[end] > num[end + 1])
        return end;
    return ret_index;
}