/*
Using a previous temp_sum to get max, if temp_sum < 0, set temp_sum to current value. If temp_sum >= 0, temp_sum += curr[i].
 */

int maxSubArray(int A[], int n) {
    if (A == NULL || n < 1)
        return 0;
    int temp_sum = A[0];
    int max_sum = temp_sum;
    for (int i = 1; i < n; i++) {
        if (temp_sum < 0)
            temp_sum = A[i];
        else
            temp_sum += A[i];
        if (temp_sum > max_sum)
            max_sum = temp_sum;
    }
    return max_sum;
}
