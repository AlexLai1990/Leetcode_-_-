/*
Solution 1: Time O(N) Space O(N)
Scan twice, one from left, one from right.  
Scanning first time is to initialize value, the second is to update.

Solution 2: Time O(N) Space O(1)
Math way:
    1. the return condition when i >= size – 1 break;
    2. jump over the equal value.
    3. care about calculating the range for increasing and decreasing sequence.
*/

// Solution 1
int candy(vector<int> &ratings) {
    int size = ratings.size();
    if (size < 2)
        return size;
    int *m_candy = new int[size];
    fill(m_candy, m_candy + size, 1);
    int sum = 0;
    int inc = 1;
    // scan from left to right
    for (int i = 1; i < size; i++) {
        if (ratings[i] > ratings[i - 1]) {
            m_candy[i] += inc;
            inc++;
        }
        else 
            inc = 1;
    }
    // scan from right to left 
    for (int i = size - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            m_candy[i] = max(m_candy[i], m_candy[i + 1] + 1);
        } 
    }
    for (int i = 0; i < size; i++)
        sum += m_candy[i];
    delete m_candy;
    return sum;
}


// Solution2
int candy(vector<int> &ratings) {
    int size = ratings.size();
    if (size < 2)
        return size; 
    int inc_range = 0;
    int inc_start = 0;
    int dec_range = 0;
    int dec_start = 0;
    int i = 0;
    int sum = size;
    while (i < size) {
        inc_start = i;
        while (i + 1 < size && ratings[i + 1] > ratings[i]) {
            i++;
        }            
        inc_range = i - inc_start;
        // calculate sum for this incrasing sequence
        sum += (inc_range * (inc_range + 1)) / 2;
        if (i >= size -1)
            break;
    
        dec_start = i;
        while (i + 1 < size && ratings[i + 1] < ratings[i]) {
            i++;
        }
        dec_range = i - dec_start - 1;
        // calculate sum for this decreasing sequence
        sum += (dec_range * (dec_range + 1)) / 2;
        if (dec_range + 1 > inc_range)
            sum += dec_range + 1 - inc_range;
        if (ratings[i] == ratings[i + 1])
            i++;
    }
    return sum;   
}