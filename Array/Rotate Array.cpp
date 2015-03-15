class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (k == 0 || n == 0 || n == 1)
            return ;
        k = k % n;
        // first rotate the whole array
        rotateRange(nums, 0, n - 1);
        // rotate the first and second part based on k
        rotateRange(nums, 0, k - 1);
        rotateRange(nums, k, n - 1);
        return ;
    }
    
    void rotateRange(int nums[], int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
        return;
    }
};