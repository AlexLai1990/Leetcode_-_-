bool canJump(int A[], int n) {
    if (n <= 1)
        return true;
    int max_reach_index = 0;
    for (int i = 0; i <= max_reach_index && max_reach_index < n - 1 ; i++) {
        if (max_reach_index < A[i] + i) 
            max_reach_index = A[i] + i;  
        // if stay in the same position return
        if (max_reach_index <= i)
            return false;
    }
    if (max_reach_index >= n - 1)
        return true;
}