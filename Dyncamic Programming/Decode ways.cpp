/*
 Current ways depends on two previous digits.
 If the first previous is not ‘0’, add its ways.
 If the result of second previous + first previous is within 10-26, 
 it means these two digits can combine with each other. 
    And we need to add the second previous ways too.
*/

int numDecodings(string s) {
    int s_len = s.length();
    if (s_len == 0 || s[0] == '0')
        return 0;
    // using previous_ways[i + 1] to store ways of s[0..i];
    vector<int> previous_ways(s_len + 1, 0);
    // initialed value
    previous_ways[0] = 1;
    previous_ways[1] = 1;
    char previous_one, previous_two;
    int value_previous_two;
    for (int i = 2; i <= s_len; i++) {
        previous_one = s[i - 1];
        // if previous != '0' add previous ways
        if (previous_one != '0') {
            previous_ways[i] = previous_ways[i - 1];
        }
        // if previuos_two belong [10,26] add previous_two ways
        // need to larger then 10, means the tenth digit should be larger than 0
        previous_two = s[i - 2];
        value_previous_two = 10 * (previous_two - '0') + previous_one - '0';
        if (value_previous_two >= 10 && value_previous_two <= 26) {
            previous_ways[i] += previous_ways[i - 2];
        }
    }
    return previous_ways[s_len];
}