/*
DP would use O(N) space,
but it can optimize by using two variables
*/

int climbStairs(int n) { 
    if (n < 1)
        return 0;
    if (n <= 2)
        return n;
    int oneStep = 1;
    int twoStep = 2;
    int result = 0;
    int start = 3;
    while (start <= n) {
        result = oneStep + twoStep;
        oneStep = twoStep;
        twoStep = result;
        start++;
    }
    
    return result;
}