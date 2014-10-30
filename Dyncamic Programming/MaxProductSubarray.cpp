/*
 DP
 Use two arrays to store the previous states.
 max_product is to recode the current max product which is calculated by max(previous max(>0) * curr_value(>0), previous min(<0) * curr_value(<0), curr_value)
 min_product is to recode the current min product which is calculated by min(prvious max(<0) * curr_value(>0), previous min( <0) * curr_value(>0), curr_value)
 In each position i, max_product[i] >= min_product[i]. So updating the max and min in each round, we just need to compare two situations not four.
 */

int maxProduct(int A[], int n) {
    if (n < 1)
        return 0;
    vector<int> max_product(n, INT_MIN);
    vector<int> min_product(n, INT_MAX);
    max_product[0] = A[0];
    min_product[0] = A[0];
    int m_max = INT_MIN;
    for (int i = 1; i < n; i++) {
        // reset each round
        int temp_max = INT_MIN;
        int temp_min = INT_MAX;
        if (A[i] == 0) {
            max_product[i] = 0;
            min_product[i] = 0;
            continue;
        }
        if (A[i] > 0 && max_product[i - 1] > 0)
            temp_max = max(temp_max, max_product[i - 1] * A[i]);
        if (A[i] < 0 && min_product[i - 1] < 0)
            temp_max = max(temp_max, min_product[i - 1] * A[i]);
        max_product[i] = max(temp_max, A[i]);
        
        if (A[i] < 0 && max_product[i - 1] > 0)
            temp_min = min(temp_min, max_product[i - 1] * A[i]);
        if (A[i] > 0 && min_product[i - 1] < 0)
            temp_min = min(temp_min, min_product[i - 1] * A[i]);
        min_product[i] = min(temp_min, A[i]);
    }
    for (int i = 0; i < n; i++) {
        if (max_product[i] > m_max)
            m_max = max_product[i];
    }
    
    return m_max;
}
