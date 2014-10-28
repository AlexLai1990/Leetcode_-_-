/*
If using DP needs O(N^2).
Each time, it needs to go through previous index to see which one jump can finish game with least steps.

Greedy thought:  
Each time try to use the current range to get to the end. 
    If some index can get to the end, end the loop
    Else 
        Update the can_jump(the range) to keep trying.
    If (i >  last_arrive) means need to a new jump. 
        Update last_arrive = previous to i’s max_reach.
Note:        
    Care return step+1 in return condition. 
    And the condition for the for loop.
*/

int jump(int A[], int n) {
    if (n <= 1)
        return 0;  
    int last_arrive = 0;
    int step = 0;
    int max_reach = 0;
    int curr_reach = 0;
    for (int i = 0; max_reach < n - 1; i++) {
        curr_reach = A[i] + i;
        if (i > last_arrive) {
            step++;
            // for arriving this point, it can go max_reach
            last_arrive = max_reach;
            // it means the next step cannot go forward, return 0
            if (max_reach < i)
                return 0;
        }
        if (curr_reach > max_reach) {
            max_reach = curr_reach;
        }
    }
    return step + 1;
}